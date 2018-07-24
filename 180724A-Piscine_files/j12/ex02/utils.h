#ifndef UTILS_H
#define UTILS_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_get_startX(char *file, int c);
int ft_get_startL(char *file, int *l);
void ft_add_line_byte(int lc, int byte, int lineBytes[11]);
void ft_print_name(char *name, int c);

#endif
