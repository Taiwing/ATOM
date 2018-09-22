#!/usr/bin/python3

# ./rmbt start_rem end_rem files..
# remove every line between the line where start_rem is found and the
# line where end_rem is found (does not remove start_rem and end_rem)

import sys

if len(sys.argv) < 2:
    sys.exit()

for i in range(1, len(sys.argv)):
    name = str(sys.argv[i])
    file = open(name)

    content = []
    for line in file:
        content.append(line)

    new = open(name, mode="w")
    bracket = 0
    for line in content:
        if '"outputs": [' in line and '"outputs": []' not in line:
            bracket += 1
            new.write(line.rstrip())
            new.write("],\n")
        elif "[" in line and bracket > 0:
            for i in line:
                if i == "[":
                    bracket += 1
        if bracket == 0:
            new.write(line)
        elif "]" in line:
            for i in line:
                if i == "]":
                    bracket -= 1

