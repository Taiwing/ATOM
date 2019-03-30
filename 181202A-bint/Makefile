CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DFLAGS	=	-g
HFLAGS	=	-I ../181118A-ft_printfv3/includes/
LFLAGS	=	../181118A-ft_printfv3/libftprintf.a
NAME	=	exec
SRC		=	*.c

all: $(NAME)

debug: $(SRC)
	$(CC) $(DFLAGS) $(HFLAGS) $(LFLAGS) $^ -o $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(HFLAGS) $(LFLAGS) $^ -o $@

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: debug all fclean re
