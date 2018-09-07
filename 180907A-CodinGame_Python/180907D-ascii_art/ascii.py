#!/usr/local/bin/python3.7

import sys
import math

l = int(input())
h = int(input())
t = input()
t = t.upper()
for i in range(h):
    line = ""
    row = input()
    for c in t:
        o = ord(c) - 65
        o = 26 if o < 0 or o > 25 else o
        line += row[o * l : o * l + l]
    print(line);
