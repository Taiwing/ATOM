CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ft_tail

ft_tail: main.o ft_tail.o ft_get_arguments.o utils.o
	$(CC) $(CFLAGS) main.o ft_tail.o ft_get_arguments.o utils.o -o ft_tail

main.o: main.c ft_tail.h ft_get_arguments.h
	$(CC) $(CFLAGS) -c main.c

ft_tail.o: ft_tail.c ft_tail.h utils.h
	$(CC) $(CFLAGS) -c ft_tail.c

ft_get_arguments.o: ft_get_arguments.c ft_get_arguments.h
	$(CC) $(CFLAGS) -c ft_get_arguments.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f main.o ft_tail.o ft_get_arguments.o utils.o
