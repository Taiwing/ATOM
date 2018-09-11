#!/usr/local/bin/python3.7

import sys
import math

width = int(input())
height = int(input())
map = []
for i in range(height):
    map.append(input())

for y in range(height):
    for x in range(width):
        if map[y][x] == "0":
            x2 = -1
            y2 = -1
            x3 = -1
            y3 = -1
            for i in range(x + 1, width):
                if map[y][i] == "0":
                    x2 = i
                    y2 = y
                    break;
            for j in range(y + 1, height):
                if map[j][x] == "0":
                    x3 = x
                    y3 = j
                    break;
            print(x, y, x2, y2, x3, y3)
