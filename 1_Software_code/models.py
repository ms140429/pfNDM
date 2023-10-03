import torch
import torch.nn as nn
import torch.nn.functional as F
import Linear


class MLP(nn.Module):
    """
    Multilayer Perceptron
    """

    def __init__(self, input_size, hidden_size, output_size, nlayers):
        super(MLP, self).__init__()
        self.nlayers = nlayers
        self.input_layer = nn.Linear(input_size, hidden_size)
        self.hidden_layers = nn.ModuleList([nn.Linear(hidden_size, hidden_size) for _ in range(nlayers - 1)])
        self.output_layer = nn.Linear(hidden_size, output_size)

    def forward(self, x):
        x = F.gelu(self.input_layer(x))
        for i in range(self.nlayers - 1):
            x = F.gelu(self.hidden_layers[i](x))
        output = self.output_layer(x)
        return output


class ConvNet(nn.Module):
    """
    1-D CNN
    """

    def __init__(self, features, seq_len, hidden_size):
        super(ConvNet, self).__init__()
        self.conv1 = nn.Conv1d(features, features, kernel_size=3, padding=1)
        self.conv2 = nn.Conv1d(features, features, kernel_size=3, padding=1)
        self.relu = nn.ReLU()
        self.pool = nn.AvgPool1d(kernel_size=2, stride=1)
        self.fc = nn.Linear(int(seq_len - 2) * features, hidden_size)

    def forward(self, x):
        """
        Args:
            x (tensor): seq_len * batch_size * features

        Returns:
            x (tensor): batch_size * hidden_size
        """
        x = x.permute(1, 2, 0)
        x = self.pool(self.relu(self.conv1(x)))
        x = self.pool(self.relu(self.conv2(x)))
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x


class Dynamic(nn.Module):
    def __init__(self, input_size, seq_len, hidden_size, output_size, nlayers, model='linear'):
        """
        Args:
            input_size (int): Dimensions of control inputs for dynamical systems
            seq_len (int): Sequence length of data for estimating the initial state of a dynamical system
            hidden_size (int): Dimensions of the hidden state
            output_size (int): Output dimensions
        """
        super().__init__()
        assert model in ['linear', 'perron'], 'Model mot support!'

        # fe is f0
        self.fe = ConvNet(output_size, seq_len, hidden_size)
        self.fu = MLP(input_size, hidden_size, hidden_size, nlayers)
        # The output matrix C
        self.fy = nn.Linear(hidden_size, output_size, bias=False)
        # The state matrix A
        if model == 'perron':
            self.fx = Linear.PerronFrobeniusLinear(hidden_size, hidden_size, bias=False)
        else:
            self.fx = nn.Linear(hidden_size, hidden_size, bias=False)

    def forward(self, x0, u):
        """
        Execute the following block-box formula:

        h{0} = f_e(x0)
        h{t+1} = f_x(h{t}) + f_u(u{t})
        y{t} = f_y(h{t})

        Args:
            x0 (tensor): seq_len * batch_size * output_size
            u (tensor): n_steps * batch_size * input_size

        Returns:
            output (tensor): n_steps * batch_size * output_size
            hidden_states (tensor): n_steps * batch_size * output_size
        """
        h = self.fe(x0)
        hidden_states, output = [h], []
        nsteps = u.shape[0]
        for step in range(nsteps):
            h = self.fx(h)
            u_t = self.fu(u[step, :, :])
            h += u_t
            y = self.fy(h)
            hidden_states.append(h)
            output.append(y)
        hidden_states, output = torch.stack(hidden_states), torch.stack(output)
        return output, hidden_states
