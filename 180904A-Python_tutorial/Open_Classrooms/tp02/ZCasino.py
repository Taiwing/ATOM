#!/usr/local/bin/python3.7

from random import randrange
from math import ceil

money = 100
ans = 'z'

while money:
	print("you have", money, "$")
	while ans != 'y' and ans != 'n':
		ans = input("do you want to bet ? (y/n): ")
	if ans == 'n':
		break
	else:
		ans = 'z'
	bet = 0
	while bet == 0 or bet > money:
		bet = int(input("how much do you want to bet ? "))
	n = -1
	while not(n > -1 and n < 50):
		n = int(input("which number do you want to bet on ? (0-49): "))
	res = randrange(50)
	print("result is:", res)
	gains = bet
	if n == res:
		gains *= 3
		print("congratulations, you won", gains, "$")
		money += gains
	elif n % 2 == res % 2:
		gains = ceil(bet/2)
		print("congratulations, you won", gains, "$")
		money += gains
	else:
		print("too bad, you lost", bet, "$")
		money -= gains

if money == 0:
	print("you are now broke !")
else:
	print("you leave with", money, "$, congratulations, you are not broke !")
