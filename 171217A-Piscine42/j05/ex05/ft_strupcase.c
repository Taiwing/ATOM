#include "libft/libft.h"
#include "ft_strupcase.h"

char *ft_strupcase(char *str)
{
  int i;

  i = 0;

  while(str[i] != 0)
  {
    if(str[i] > 96 && str[i] < 123)
      str[i] -= 32;
    i++;
  }

  return str;
}
