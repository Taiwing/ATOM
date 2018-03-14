CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -lm -lft -lallegro -lconfig
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
MNIST_helper.c\
data_helper.c\
print.c\
evaluate.c\
training.c\
GD.c\
config_w.c\
config_r.c\
test.c\

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
