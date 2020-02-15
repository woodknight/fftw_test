import numpy as np

W = 8
H = 8

# load numpy fft
with open("input_fft_real.bin", "rb") as f:
    np_fft_r = np.fromfile(f, np.float32)
np_fft_r = np.reshape(np_fft_r, (H, W))

# print(np_fft_r[0])

# load fftw fft
with open("output_fftw_r.bin", "rb") as f:
    fftw_fft_r = np.fromfile(f, np.float32)
fftw_fft_r = np.reshape(fftw_fft_r, (H, W))

print(np_fft_r - fftw_fft_r)