NAME = libf4.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ODIR = obj

LFT = libf4.h
SRC = ft_strlen.c\
ft_memalloc.c\
ft_memdel.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_striteri.c\
ft_strmap.c\
ft_strmapi.c\
ft_strequ.c\
ft_strnequ.c\
ft_strsub.c\
ft_strjoin.c\
ft_strtrim.c\

OBJ = $(addprefix $(ODIR)/, $(SRC:.c=.o))

all: $(NAME) test

${ODIR}/%.o: %.c $(LFT)
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

test: main.c $(NAME) $(LFT)
	$(CC) $(CFLAGS) -o $@ $< -L. -lf4

clean:
	rm -Rf $(ODIR)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY: all clean fclean re
