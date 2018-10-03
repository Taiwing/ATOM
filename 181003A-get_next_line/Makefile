CC=gcc
CFLAGS= -c -Wall -Wextra -Werror
HFLAGS= -I libft/includes
LFLAGS= -L libft/ -lft
NAME=test_gnl
SRC=get_next_line.c\
main.c
OBJ=$(SRC:.c=.o)
LIB=libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ) $(HFLAGS) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $< $(HFLAGS)

$(LIB):
	make -C libft/ fclean
	make -C libft/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
