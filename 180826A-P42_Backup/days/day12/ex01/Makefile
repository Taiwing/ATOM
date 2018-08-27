CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=ft_cat

all: $(NAME)

$(NAME): ft_cat.o
	$(CC) $(CFLAGS) $^ -o $@

ft_display.o: ft_cat.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ft_cat.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
