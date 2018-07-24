#include "libft/libft.h"
#include "ft_strcpy.h"

char *ft_strcpy(char *dest, char *src)
{
  int i;

  while(1)
  {
    dest[i] = src[i];
    if(dest[i] == '\0')
      break;
    i++;
  }

  return dest;
}
