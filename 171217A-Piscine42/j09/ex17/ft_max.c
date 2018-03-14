#include "ft_max.h"

int ft_max(int *tab, int length)
{
  int i;
  int max;

  i = 1;
  max = length ? tab[0] : 0;

  while(i < length)
  {
    max = (tab[i] > max) ? tab[i] : max;
    i++;
  }

  return max;
}
