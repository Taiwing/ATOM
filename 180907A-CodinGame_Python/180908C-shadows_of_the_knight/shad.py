#!/usr/local/bin/python3.7

import sys
import math

w, h = [int(i) for i in input().split()]
n = int(input())
x, y = [int(i) for i in input().split()]

ul = [0, 0]
dr = [w-1, h-1]

while True:
    dir = input()
    if "R" in dir:
        ul[0] = x + 1
    if "D" in dir:
        ul[1] = y + 1
    if "L" in dir:
        dr[0] = x - 1
    if "U" in dir:
        dr[1] = y - 1
    if len(dir) == 1:
        if "L" in dir or "R" in dir:
            ul[1] = dr[1] = y
        else:
            ul[0] = dr[0] = x
    mx = int(round((dr[0] - ul[0]) / 2))
    my = int(round((dr[1] - ul[1]) / 2))
    if ("L" in dir or "R" in dir) and mx == 0:
        mx += 1
    if ("U" in dir or "D" in dir) and my == 0:
        my += 1
    x += mx if "R" in dir else -mx
    y += my if "D" in dir else -my
    print(x, y)
