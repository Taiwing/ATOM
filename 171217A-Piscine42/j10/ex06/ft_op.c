#include "ft_op.h"

int ft_add(int a, int b)
{
  return a+b;
}

int ft_minus(int a, int b)
{
  return a-b;
}

int ft_multiply(int a, int b)
{
  return a*b;
}

int ft_divide(int a, int b)
{
  return a/b;
}

int ft_mod(int a, int b)
{
  return a%b;
}

int ft_power(int a, int b)
{
  if(!b)
    return 1;
  else if(b > 0)
    return a * ft_power(a, b-1);
  else if(b < 0)
    return (1/a) * ft_power(a, b+1);
}
