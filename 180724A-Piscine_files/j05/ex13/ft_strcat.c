#include "libft/libft.h"
#include "ft_strcat.h"

char *ft_strcat(char *dest, char *src)
{
  int i;
  int j;

  i = 0;
  j = 0;

  while(dest[i])
    i++;

  while(1)
  {
    dest[i+j] = src[j];
    if(!dest[i+j])
      return dest;
    j++;
  }
}
