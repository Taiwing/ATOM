NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@ -L../180614A-Libft -lf4

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
