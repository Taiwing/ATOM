#include "ft_strdup.h"
#include <stdlib.h>

char *ft_strdup(char *src)
{
  int i;
  char *dup;

  i = 0;
  dup = malloc(sizeof(src));

  while(src[i])
  {
    dup[i] = src[i];
    i++;
  }

  dup[i] = '\0';

  return dup;
}
