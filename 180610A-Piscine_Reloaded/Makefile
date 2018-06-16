NAME = libf3.a

LIBPATH = /usr/local/lib/

OBJ = ft_putchar.o\
ex06/ft_print_alphabet.o\
ex07/ft_print_numbers.o\
ex08/ft_is_negative.o\
ex09/ft_ft.o\
ex10/ft_swap.o\
ex11/ft_div_mod.o\
ex12/ft_iterative_factorial.o\
ex13/ft_recursive_factorial.o\
ex14/ft_sqrt.o\
ex15/ft_putstr.o\
ex16/ft_strlen.o\
ex17/ft_strcmp.o\
ex20/ft_strdup.o\
ex21/ft_range.o\
ex25/ft_foreach.o\
ex26/ft_count_if.o\

all: $(NAME) test

%.o: %.c
	gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(LIBPATH)$(NAME) $(OBJ)
	ranlib $(LIBPATH)$(NAME)

test:
	gcc main.c -o $@ -lf3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBPATH)$(NAME)
	rm -f test

remove: fclean
	mv /usr/local/include/libf3.h .

re: fclean all
