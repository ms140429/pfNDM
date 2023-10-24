import math
import torch
from torch import nn
from abc import ABC, abstractmethod


class LinearBase(nn.Module, ABC):
    def __init__(self, insize, outsize, bias=False, provide_weights=True):
        super().__init__()
        self.in_features, self.out_features = insize, outsize
        self.bias = nn.Parameter(torch.zeros(1, outsize), requires_grad=bias)
        if provide_weights:
            self.weight = nn.Parameter(torch.Tensor(insize, outsize))
            torch.nn.init.kaiming_uniform_(self.weight, a=math.sqrt(5))

    def eig(self):
        if self.in_features == self.out_features:
            eigenvalues, _ = torch.linalg.eig(self.effective_W())
        else:
            _, eigenvalues, _ = torch.linalg.svd(self.effective_W())
        return eigenvalues

    @abstractmethod
    def effective_W(self):
        pass

    def forward(self, x):
        return torch.matmul(x, self.effective_W()) + self.bias


class Linear(LinearBase):
    def __init__(self, insize, outsize, bias=True):
        super().__init__(insize, outsize, bias=bias, provide_weights=False)
        self.linear = nn.Linear(insize, outsize, bias=bias)
        self.weight = self.linear.weight
        self.bias = self.linear.bias

    def effective_W(self):
        return self.linear.weight.T

    def forward(self, x):
        return self.linear(x)


class PerronFrobeniusLinear(LinearBase):
    """
    Trainable matrix constrained by the Perron-Frobenius theorem.
    Trainable parameters include the original weights and a scaling matrix.
    """
    def __init__(self, insize, outsize, bias=False, lambda_min=0.1, lambda_max=0.999):
        super().__init__(insize, outsize, bias=bias, provide_weights=True)
        self.scaling = nn.Parameter(torch.rand(insize, outsize))
        self.sigma_min = lambda_min
        self.sigma_max = lambda_max

    def effective_W(self):
        s_clamped = self.sigma_max - (self.sigma_max - self.sigma_min) * torch.sigmoid(self.scaling)
        w_sofmax = s_clamped * nn.functional.softmax(self.weight, dim=1)
        return w_sofmax
