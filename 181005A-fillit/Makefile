CC=gcc
CFLAGS= -g -Wall -Wextra -Werror
LFLAGS= -lft
NAME=fillit
SRC=main.c\
parser.c\
solver.c\
tetros.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LFLAGS)

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
