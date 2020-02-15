import numpy as np

W = 8
H = 8

input = np.random.random((H, W)).astype(np.float32)

input.tofile("input.bin")

input_fft = np.fft.fft2(input, axes=(0, 1))
input_fft.real.astype(np.float32).tofile("input_fft_real.bin")
input_fft.imag.astype(np.float32).tofile("input_fft_imag.bin")

# print(input_fft.real.astype(np.float32))