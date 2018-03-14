CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lm -lft
NAME = sn

SRC = main.c\
params.c\
config.c\
neural_struct.c\
activation_functions.c\
derivative_functions.c\
data_processing.c\
learning.c\
SGD.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC) $(LFLAGS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
