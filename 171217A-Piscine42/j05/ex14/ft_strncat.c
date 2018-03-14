#include "libft/libft.h"
#include "ft_strncat.h"

char *ft_strncat(char *dest, char *src, int nb)
{
  int i;
  int j;

  i = 0;
  j = 0;

  while(dest[i])
    i++;

  while(j != nb)
  {
    dest[i+j] = src[j];
    j++;
  }

  dest[i+j] = '\0';
  return dest;
}
