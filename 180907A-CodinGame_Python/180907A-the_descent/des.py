#!/usr/local/bin/python3.7

import sys
import math

while True:
	max = 0
	imax = 0
    for i in range(8):
        mountain_h = int(input())
        if mountain_h > max:
            max = mountain_h
            imax = i
    print(imax)
