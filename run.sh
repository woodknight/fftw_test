#!/bin/bash
make

W=4

python simple_fft1.py
./simple_fft1 ${W}
