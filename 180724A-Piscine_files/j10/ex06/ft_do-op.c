#include "ft_do-op.h"

void ft_doop(int *num[3], int(*op)(int, int))
{
  if(!op)
    *(num[2]) = 0;
  else if(!(*(num[1])) && op ==  &ft_divide)
  {
    num[2] = 0;
    ft_putstr("Stop : division by zero\n");
  }
  else if(!(*(num[1])) && op ==  &ft_mod)
  {
    num[2] = 0;
    ft_putstr("Stop : modulo by zero\n");
  }
  else
    *(num[2]) = (*op)(*(num[0]), *(num[1]));
}

int (*ft_find_op(char sym))(int, int)
{
  if(sym == '+')
    return &ft_add;
  else if(sym == '-')
    return &ft_minus;
  else if(sym == '*')
    return &ft_multiply;
  else if(sym == '/')
    return &ft_divide;
  else if(sym == '%')
    return &ft_mod;
  else if(sym == '^')
    return &ft_power;
  else
    return 0;
}
