#ifndef FT_GET_ARGUMENTS_H
#define FT_GET_ARGUMENTS_H
#include "ft_utils.h"

int ft_get_arguments(int *C, int *fc, char **fv, char **av);
int ft_is_C_option(char *str);
int ft_does_file_exist(char *file);

#endif
