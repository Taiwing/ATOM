#!/usr/local/bin/python3.7

import sys
import math

def distance(lat1, lon1, lat2, lon2):
    x = (lon2 - lon1) * math.cos((lat1 + lat2) / 2)
    y = lat2 - lat1
    return math.sqrt(x * x + y * y) * 6371

lon = float(input().replace(",", "."))
lat = float(input().replace(",", "."))
n = int(input())
d = -1
name = ""
for i in range(n):
    defib = input().split(";")
    defib[-1] = defib[-1].replace(",", ".")
    defib[-2] = defib[-2].replace(",", ".")
    if d == -1 or distance(lat, lon, float(defib[-1]), float(defib[-2])) < d:
        d =  distance(lat, lon, float(defib[-1]), float(defib[-2]))
        name = defib[1]
print(name)
