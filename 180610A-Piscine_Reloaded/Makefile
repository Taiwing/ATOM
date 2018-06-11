NAME = libf3.a

LIBPATH = /usr/local/lib/

OBJ = ft_putchar.o\
ex06/ft_print_alphabet.o\
ex07/ft_print_numbers.o\
ex08/ft_is_negative.o\

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
