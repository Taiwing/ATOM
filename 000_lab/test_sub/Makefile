############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
FT_PRINTFD		=	ft_printf
FT__PRINTFD		=	ft_\ printf
L________LLD		=	l\ \ \ \ \ \ \ \ ll
HFLAGS		=	-I $(HDIR) -I $(FT_PRINTFD)/$(HDIR) -I $(FT__PRINTFD)/$(HDIR) -I $(L________LLD)/$(HDIR)
NAME		=	exec

############################## SOURCES #########################################

SRCDIR			=	src

SRCC			=	main.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(SRCC))

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): libftprintf.a "l  o  l" lib3.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ))

libftprintf.a:
	make -C $(SRCDIR)/$(FT_PRINTFD)

"l  o  l":
	make -C $(SRCDIR)/$(FT__PRINTFD)

lib3.a:
	make -C $(SRCDIR)/$(L________LLD)

main.o: ft_printf.h
%.o: %.c
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
