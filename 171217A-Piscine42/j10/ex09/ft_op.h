#ifndef FT_OP_H
#define FT_OP_H

#include "ft_usage.h"

int ft_sub(int a, int b);
int ft_add(int a, int b);
int ft_mul(int a, int b);
int ft_div(int a, int b);
int ft_mod(int a, int b);

typedef struct s_opp
{
  char *op;
  int(*f)(int, int);
} t_opp;

#endif
