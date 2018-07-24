#ifndef FT_DOOP_H
#define FT_DOOP_H
#include "ft_op.h"
#include "ft_utils.h"

void ft_doop(int *num[3], int(*op)(int, int));
int (*ft_find_op(char sym))(int, int);

#endif
