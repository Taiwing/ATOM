CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -Iincludes
NAME = libft.a
SDIR = srcs
SRC = ft_putchar.c\
ft_putstr.c\
ft_strcmp.c\
ft_strlen.c\
ft_swap.c
OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
