import sys
import math

res = 5526
n = int(input())
for i in input().split():
    t = int(i)
    res = t if math.fabs(t) < math.fabs(res) or (t > 0 and t == res * -1) else res

print(res if n else 0)
