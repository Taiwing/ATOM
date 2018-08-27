CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=ft_display_file

all: $(NAME)

$(NAME): ft_display.o
	$(CC) $(CFLAGS) $^ -o $@

ft_display.o: ft_display.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ft_display.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
