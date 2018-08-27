CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=ft_advanced_do-op

all: $(NAME)

$(NAME): main.o get_op.o ops.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $<

get_op.o: get_op.c
	$(CC) $(CFLAGS) -c $<

ops.o: ops.c
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f main.o get_op.o ops.o utils.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
