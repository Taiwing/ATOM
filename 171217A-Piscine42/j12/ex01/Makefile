CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ft_cat

ft_cat: main.o ft_cat.o
	$(CC) $(CFLAGS) main.o ft_cat.o -o ft_cat

main.o: main.c ft_cat.h
	$(CC) -c main.c

ft_cat.o: ft_cat.c ft_cat.h
	$(CC) -c ft_cat.c

clean:
	rm -f main.o ft_cat.o
