#!/usr/local/bin/python3.7

year = int(input("year: "))

if year % 4 or (year % 100 == 0 and year % 400):
	print("unisex")
else:
	print("bisex")
