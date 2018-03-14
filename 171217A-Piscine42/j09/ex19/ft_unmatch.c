#include "ft_unmatch.h"

int ft_unmatch(int *tab, int length)
{
  int i;
  int j;
  int count;

  i = 0;

  while(i < length)
  {
    j = 0;
    count = 0;
    while(j < length)
    {
      count = tab[j] == tab[i] ? count+1 : count;
      j++;
    }
    if(count%2)
      break;
    i++;
  }

  return tab[i];
}
