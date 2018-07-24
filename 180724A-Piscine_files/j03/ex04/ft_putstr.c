#include "libft/libft.h"
#include "ft_putstr.h"

void ft_putstr(char *str)
{
  int i;

  i = 0;

  while(str[i] != '\0')
  {
    ft_putchar(str[i]);
    i++;
  }
}
