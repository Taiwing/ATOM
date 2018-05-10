#include "libft.h"

int ft_pow(int a, int b)
{
  if(!b)
    return 1;
  else
    return a * ft_pow(a, b-1);
}