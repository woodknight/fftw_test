import numpy as np

W = 4
H = 4

a = np.arange(W * H)
a = np.reshape(a, (H, W))
print(a)
print(np.fft.fft2(a))