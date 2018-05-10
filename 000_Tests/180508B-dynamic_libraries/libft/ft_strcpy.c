#include "libft.h"

char *ft_strcpy(char *dest, char *src)
{
  int i;

  i = 0;

  while(1)
  {
    dest[i] = src[i];
    if(!dest[i])
      return dest;
    i++;
  }
}
