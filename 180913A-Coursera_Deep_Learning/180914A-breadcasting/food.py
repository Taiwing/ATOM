#!/usr/bin/python3

import numpy as np

f = np.transpose(np.array([[56.0, 0.0, 4.4, 68.0], [1.2, 104.0, 52.0, 8.0], [1.8, 135.0, 99.0, 0.9]]))

print(f)

food = ["apples", "beef", "eggs", "potatoes"]
comp = ["carb", "protein", "fat"]


print("\nLoop:")
for i in range(4):
    print(food[i]+":")
    total = 0
    for j in range(3):
        total += f[i][j]
    total /= 100
    for j in range(3):
        print(comp[j]+": "+str(f[i][j]/total)+"%")

print("\nNo loop:")
p = f.sum(axis=1)/100
print(p)
r = np.divide(np.transpose(f), p)
print(r)

print("\nNo loop and reshape:")
p = p.reshape(1, 4)
print(p)
r = np.transpose(f)/p
print(r)
