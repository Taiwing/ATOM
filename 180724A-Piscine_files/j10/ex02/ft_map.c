#include "ft_map.h"

int *ft_map(int *tab, int length, int(*f)(int))
{
  int i;
  int *out;

  i = 0;
  out = (int *)malloc(length * sizeof(int));

  while(i < length)
  {
    out[i] = (*f)(tab[i]);
    i++;
  }

  return out;
}
