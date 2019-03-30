############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
HFLAGS		=	-I $(HDIR)
NAME		=	exec

############################## SOURCES #########################################

SRCDIR			=	src

SRCC			=	ft_getopt.c\
					get_next_option_argument.c\
					get_short_option.c\
					getopt_errors.c\
					getopt_long_errors.c\
					getopt_utils.c\
					init_getopt.c\
					main.c\
					permute_order.c\
					process_long_option.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(SRCC))

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ))

ft_getopt.o: get_next_option_argument.h ft_getopt.h get_short_option.h
get_next_option_argument.o: permute_order.h ft_getopt.h process_long_option.h\
	getopt_utils.h
get_short_option.o: ft_getopt.h getopt_utils.h getopt_errors.h
getopt_errors.o: ft_getopt.h getopt_utils.h
getopt_long_errors.o: getopt_errors.h ft_getopt.h getopt_utils.h
getopt_utils.o: getopt_utils.h
init_getopt.o: ft_getopt.h
main.o: ft_getopt.h
permute_order.o: ft_getopt.h
process_long_option.o: ft_getopt.h getopt_utils.h getopt_errors.h
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
