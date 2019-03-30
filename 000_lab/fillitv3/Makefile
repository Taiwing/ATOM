############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
HFLAGS		=	-I $(HDIR)
NAME		=	fillit

############################## SOURCES #########################################

SRCDIR			=	src

DATADIR			=	data
UTILSDIR		=	utils

SRCC			=	main.c\

DATAC			=	tetros.c\

UTILSC			=	error.c\
					parser.c\
					solver.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(DATAC))\
					$(patsubst %.c,%.o,$(UTILSC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.c	$(SRCDIR)/$(DATADIR)
vpath			%.c	$(SRCDIR)/$(UTILSDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ))

tetros.o: tetros.h
main.o: main.h parser.h solver.h error.h
error.o: error.h
parser.o: tetros.h error.h
solver.o: solver.h tetros.h error.h
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
