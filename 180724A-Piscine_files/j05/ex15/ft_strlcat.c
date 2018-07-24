#include "libft/libft.h"
#include "ft_strlcat.h"

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
  int i;
  int j;

  i = 0;
  j = 0;

  while(dest[i])
    i++;

  while(j+i < size-1 && src[j])
  {
    dest[i+j] = src[j];
    j++;
  }
  dest[i+j] = '\0';

  while(src[j])
    j++;

  return i+j;
}
