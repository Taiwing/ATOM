#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <errno.h>

void ft_puterr(char *str);
void print_arg_error(int argc, char **argv);
void print_file_error(char *file);

#endif
