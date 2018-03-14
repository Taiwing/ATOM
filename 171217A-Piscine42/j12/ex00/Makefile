CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ft_display_file

ft_display_file: main.o ft_display_file.o
	$(CC) -o ft_display_file main.o ft_display_file.o

main.o: main.c ft_display_file.h
	$(CC) $(CFLAGS) -c main.c

ft_display_file.o: ft_display_file.c ft_display_file.h
	$(CC) $(CFLAGS) -c ft_display_file.c

clean:
	rm main.o ft_display_file.o
