CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -Iincludes
NAME=libft.a

all: $(NAME)

$(NAME): ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	ranlib libft.a

ft_putchar.o: srcs/ft_putchar.c
	$(CC) $(CFLAGS) $<

ft_putstr.o: srcs/ft_putstr.c
	$(CC) $(CFLAGS) $<

ft_strcmp.o: srcs/ft_strcmp.c
	$(CC) $(CFLAGS) $<

ft_strlen.o: srcs/ft_strlen.c
	$(CC) $(CFLAGS) $<

ft_swap.o: srcs/ft_swap.c
	$(CC) $(CFLAGS) $<

clean:
	rm -f ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
