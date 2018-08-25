CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_tail

all: $(NAME)

$(NAME): main.o ft_tail.o error.o utils.o
	$(CC) $(CFLAGS) main.o ft_tail.o error.o utils.o -o ft_tail

main.o: main.c ft_tail.h error.h utils.h
	$(CC) $(CFLAGS) -c main.c

ft_tail.o: ft_tail.c ft_tail.h utils.h
	$(CC) $(CFLAGS) -c ft_tail.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f main.o ft_tail.o error.o utils.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
