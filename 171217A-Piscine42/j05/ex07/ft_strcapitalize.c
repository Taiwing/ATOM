#include "libft/libft.h"
#include "ft_strcapitalize.h"

char *ft_strcapitalize(char *str)
{
  int i;
  int w;

  w = 0;
  i = 0;

  while(str[i])
  {
    if((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91)
       || (str[i] > 96 && str[i] < 123))
      w++;
    else
      w = 0;
    str[i] = (w == 1 && (str[i] > 96 && str[i] < 123)) ? str[i] - 32 : str[i];
    str[i] = (w > 1 && (str[i] > 64 && str[i] < 91)) ? str[i] + 32 : str[i];
    i++;
  }

  return str;
}
