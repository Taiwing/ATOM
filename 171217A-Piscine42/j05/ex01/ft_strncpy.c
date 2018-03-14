#include "libft/libft.h"
#include "ft_strncpy.h"

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
  int i;
  int eos;

  while(i < n)
  {
    eos = src[i] == '\0' ? 1 : 0;
    dest[i] = eos ? '\0' : src[i];
    i++;
  }

  if(!eos && dest[i-1] != '\0')
    dest[i] = '\0';

  return dest;
}
