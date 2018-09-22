#!/usr/bin/python3

# ./rmsw to_del files..
# remove every line starting with to_del
# put a '$' in front of 'to_del' to interpret special characters in bash

import sys

if len(sys.argv) < 3:
    sys.exit()

to_del = sys.argv[1]

for i in range(2, len(sys.argv)):
    name = str(sys.argv[i])
    file = open(name)

    content = []
    for line in file:
        content.append(line)

    new = open(name, mode="w")
    for line in content:
        if line[:len(to_del)] != to_del:
            new.write(line)

