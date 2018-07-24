#include "libft/libft.h"
#include "ft_strlcpy.h"

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
  int i;
  int eos;

  i = 0;
  eos = 0;

  while(!eos)
  {
    eos = src[i] == '\0' ? 1 : 0;
    if(i < size-1)
      dest[i] = eos ? '\0' : src[i];
    i++;
  }

  return i;
}
