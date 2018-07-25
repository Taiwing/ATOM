#include "libft/libft.h"
#include "ft_strlen.h"

int ft_strlen(char *str)
{
  int n;

  n = -1;
  while(str[++n]);
  return n;
}
