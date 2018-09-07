import sys
import math

def norrify(bins):
	ret = ""
	l = len(bins)
	i = 0
	while i < l:
		bit = bins[i]
		if i > 0:
			ret += " "
		ret += "0 " if bit == "1" else "00 "
		while i < l and bins[i] == bit:
			ret += "0"
			i += 1
	return ret

message = input()
zeros = "00000000"
bit = -1
code = ""

for c in message:
	bins = bin(ord(c)).lstrip("0b")
	if len(bins) < 7:
		bins = zeros[: 7 - len(bins)] + bins
	bins = norrify(bins)
	if bit == -1 or (bit == 0 and bins[:2] == "0 ")  or (bit == 1 and bins[:3] == "00 "):
		code += bins if bit == -1 else " " + bins
	else:
		code += bins[3:] if bit == 0 else bins[2:]
	sp = bins.split()
	bit = 1 if sp[-2] == "0" else 0

print(code)
