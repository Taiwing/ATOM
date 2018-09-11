#!/usr/local/bin/python3.7

import sys
import math

def getlvlex(graph, exits, pos, lvl):
    ret = []
    if lvl == 0:
        for i in graph[pos]:
            if i in exits:
                ret = [pos, i]
                break
    else:
        for i in graph[pos]:
            ret = getlvlex(graph, exits, i, lvl - 1)
            if ret != []:
                break
    return ret

def closex(graph, exits, sky):
    ret = []
    lvl = 0
    while ret == []:
        ret = getlvlex(graph, exits, sky, lvl)
        lvl += 1
    return ret

n, l, e = [int(i) for i in input().split()]
graph = {}
for i in range(l):
    n1, n2 = [int(j) for j in input().split()]
    if n1 not in graph:
        graph[n1] = []
    if n2 not in graph:
        graph[n2] = []
    graph[n1].append(n2)
    graph[n2].append(n1)
exits = []
for i in range(e):
    exits.append(int(input()))

# game loop
while True:
    si = int(input())
    lnk = closex(graph, exits, si)
    print(lnk[0], lnk[1])
