#include "ft_range.h"
#include <stdlib.h>

int *ft_range(int min, int max)
{
  int *tab;
  int i;

  tab = (max - min) > 0 ? malloc((max - min) * sizeof(int)) : NULL;
  i = 0;

  while(min < max)
  {
    tab[i] = min;
    min++;
    i++;
  }

  return tab;
}
