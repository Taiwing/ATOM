NAME = libft.a

SRC = srcs/ft_putchar.c\
srcs/ft_putstr.c\
srcs/ft_strcmp.c\
srcs/ft_strlen.c\
srcs/ft_swap.c\

OBJ = srcs/ft_putchar.o\
srcs/ft_putstr.o\
srcs/ft_strcmp.o\
srcs/ft_strlen.o\
srcs/ft_swap.o\

INC = includes/libft.h

all: $(NAME)

$(OBJ):
	gcc -Wall -Wextra -Werror -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	gcc -Wall -Wextra -Werror -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	gcc -Wall -Wextra -Werror -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	gcc -Wall -Wextra -Werror -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	gcc -Wall -Wextra -Werror -c srcs/ft_swap.c -o srcs/ft_swap.o

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
