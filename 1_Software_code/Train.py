import argparse
import torch
from torch import nn
import LoadData as ld
import models
import adan
import util

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")


def Train(arguments):
    util.seed_torch(arguments.seed)

    # DataSet
    train, valid, test = ld.loadData(windows=arguments.estimate_window + arguments.predict_window,
                                     samples=arguments.train_samples, down=arguments.down_rate)
    train, valid, test = util.to_tensor(train).to(device), util.to_tensor(valid).to(device), \
                         util.to_tensor(test).to(device)
    print(train.shape, valid.shape, test.shape)

    valid_true = valid[:, arguments.estimate_window:, arguments.control:].permute(1, 0, 2)
    test_true = test[:, arguments.estimate_window:, arguments.control:].permute(1, 0, 2)
    train_loader = ld.loader(train, arguments.estimate_window, arguments.batch, arguments.control)

    # Init the structured linear neural dynamics model
    dynamic = models.Dynamic(arguments.control, arguments.estimate_window, arguments.hidden_size, arguments.features,
                          arguments.n_layers, arguments.model).to(device)
    print(f'Total parameters of {arguments.model} is {util.get_parameters(dynamic)}')

    # Train
    SMAE = nn.SmoothL1Loss()
    MSE = nn.MSELoss()
    if arguments.train:
        optimizer = adan.Adan(dynamic.parameters(), lr=1e-3)
        early_stop = util.EarlyStopping(patience=100, cold=3, path=f'checkpoints/{arguments.model}.pth')
        for epoch in range(arguments.epochs):
            for step, (oc, data, label) in enumerate(train_loader):
                label = label.permute(1, 0, 2)
                output, hidden_states = dynamic(data.permute(1, 0, 2), oc.permute(1, 0, 2))
                r_loss = SMAE(label, output)
                # Physics-informed loss
                p_loss = SMAE(torch.abs(hidden_states[:-1, :, :]), torch.abs(hidden_states[1:, :, :]))
                loss = r_loss + 0.1 * p_loss
                optimizer.zero_grad()
                loss.backward()
                optimizer.step()

            # Valid
            with torch.no_grad():
                val_o, _ = dynamic(valid[:, 0:arguments.estimate_window, arguments.control:].permute(1, 0, 2),
                                   valid[:, arguments.estimate_window:, 0:arguments.control].permute(1, 0, 2))
                val_loss = SMAE(100 * val_o, 100 * valid_true)
                valid_MSE = MSE(100 * val_o, 100 * valid_true)

            early_stop(val_loss, dynamic, optimizer)

            # Print the losses
            if epoch % arguments.print_rate == 0:
                print('epoch:%-5d train_loss: %-12.3e smooth_loss: %-12.3e valid_loss: %-9.3f '
                      'learning rate: %.1e' %
                      (epoch, util.to_numpy(r_loss), util.to_numpy(p_loss), util.to_numpy(valid_MSE),
                       optimizer.param_groups[0]['lr']))
            if early_stop.early_stop:
                break

    # Test
    if arguments.predict:
        dynamic.load_state_dict(torch.load(f'./checkpoints/{arguments.model}.pth'))

        test_pred, _ = dynamic(test[:, 0:arguments.estimate_window, arguments.control:].permute(1, 0, 2),
                               test[:, arguments.estimate_window:, 0:arguments.control].permute(1, 0, 2))
        test_loss = MSE(100 * test_pred, 100 * test_true)
        print('Test Loss: %.5f' % test_loss)


parser = argparse.ArgumentParser(description='Train configs')
parser.add_argument('--seed', type=int, default=2023, help='Random seed')
parser.add_argument('--down_rate', type=int, default=8, help='Down sample rate')
parser.add_argument('--estimate_window', type=int, default=16, help='Seq_len for estimate the h0')
parser.add_argument('--predict_window', type=int, default=128, help='Seq_len for predict')
parser.add_argument('--train_samples', type=int, default=30000, help='Nums of the train samples')
parser.add_argument('--control', type=int, default=10, help='The control input dimension')
parser.add_argument('--print_rate', type=int, default=1, help='The rate of printing')
parser.add_argument('--features', type=int, default=4, help='The output dimension')
parser.add_argument('--hidden_size', type=int, default=48, help='Hidden_size of each hidden layer')
parser.add_argument('--batch', type=int, default=1024, help='Batch size for training process')
parser.add_argument('--epochs', type=int, default=5000, help='Max epoch for training process')
parser.add_argument('--n_layers', type=int, default=3, help='Nums of layers for MLP')
parser.add_argument('--model', type=str, default='perron', choices=['perron', 'linear'])
parser.add_argument('--train', type=bool, default=False, help='Train or just load the checkpoint for testing')
parser.add_argument('--predict', type=bool, default=True, help='Whether to evaluate on the test set?')
args = parser.parse_args()

Train(arguments=args)
