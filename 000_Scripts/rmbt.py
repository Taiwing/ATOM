#!/usr/bin/python3

# ./rmbt start_rem end_rem files..
# remove every line between the line where start_rem is found and the
# line where end_rem is found (does not remove start_rem and end_rem)

import sys

if len(sys.argv) < 4:
    sys.exit()

start_rem = str(sys.argv[1])
end_rem = str(sys.argv[2])

for i in range(3, len(sys.argv)):
    name = str(sys.argv[i])
    file = open(name)

    content = []
    for line in file:
        content.append(line)

    new = open(name, mode="w")
    code = 0
    for line in content:
        if end_rem in line:
            code = 0
        if code == 0:
            new.write(line)
        if start_rem in line:
            code = 1

