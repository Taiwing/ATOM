import sys
import math

light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

x = initial_tx
y = initial_ty

while True:
    remaining_turns = int(input())
    dir = ""
    if y != light_y:
        dir += "S" if y < light_y else "N"
        y += 1 if y < light_y else -1
    if x != light_x:
        dir += "E" if x < light_x else "W"
        x += 1 if x < light_x else -1
    print(dir)
