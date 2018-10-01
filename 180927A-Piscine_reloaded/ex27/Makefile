CC = gcc
CFLAGS = -Wall -Wextra -Werror -o
NAME = ft_display_file
SRC = main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $< $(CFLAGS) $@

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
