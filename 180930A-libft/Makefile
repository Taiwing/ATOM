CC=gcc
CFLAGS= -c -Wall -Wextra -Werror
NAME=libft.a
SRC=
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $<
	ranlib $@

%.o: %.c libft.h	
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
