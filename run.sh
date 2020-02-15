#!/bin/bash

PYTHON=/home/jiang/anaconda3/bin/python
W=8
H=8

${PYTHON} make_data.py
./main ${W} ${H}
${PYTHON} check_data.py