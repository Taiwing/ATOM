CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = ft_hexdump

SRC = main.c\
ft_get_arguments.c\
ft_hexdump.c\
ft_prints.c\
ft_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
