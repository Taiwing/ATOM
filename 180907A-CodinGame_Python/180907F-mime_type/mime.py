#!/usr/local/bin/python3.7

import sys
import math

n = int(input())
q = int(input())
table = {}
for i in range(n):
    ext, mt = input().split()
    table[ext.lower()] = mt
for i in range(q):
    fname = input()
    sp = fname.rsplit(".", 1)
    ext = sp[-1].lower()
    if ext != fname and ext in table:
        print(table[ext])
    else:
        print("UNKNOWN")
