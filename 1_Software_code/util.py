import os
import random

import numpy as np
import torch

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")


def seed_torch(seed=1234):
    random.seed(seed)
    os.environ['PATHOGENS'] = str(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.cuda.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    torch.backends.cudnn.benchmark = False
    torch.backends.cudnn.deterministic = True


def to_tensor(arr):
    return torch.tensor(arr, dtype=torch.float32)


def to_numpy(tensor):
    return tensor.cpu().detach().numpy()


def Spectral_Radius(eig):
    return ["{:.3f}".format(to_numpy(torch.max(torch.abs(torch.real(e)))).item()) for e in eig] if isinstance(eig, list) \
        else ["{:.3f}".format(to_numpy(max(torch.abs(torch.real(eig)))))]


def get_parameters(model):
    trainable_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
    return trainable_params


class EarlyStopping:
    def __init__(self, patience, cold, path='./checkpoint/Dynamic/dynamic.pth'):
        self.patience = patience
        self.cold = cold
        self.counter_p = 0
        self.counter_c = 0
        self.early_stop = False
        self.val_loss_min = np.Inf
        self.path = path

    def __call__(self, val_loss, model, optimizer):
        if val_loss < self.val_loss_min:
            self.val_loss_min = val_loss
            self.save_checkpoint(model)
            self.counter_p = 0
        elif val_loss >= self.val_loss_min:
            self.counter_p += 1
            if self.counter_p > self.patience:
                self.counter_c += 1
                if self.counter_c > self.cold:
                    self.early_stop = True
                optimizer.param_groups[0]['lr'] /= 5
                self.counter_p = 0

    def save_checkpoint(self, model):
        torch.save(model.state_dict(), self.path)
