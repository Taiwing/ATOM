#include "ft_compact.h"

int ft_compact(char **tab, int length)
{
  int i;
  int j;
  int l;

  i = 0;
  l = length;

  while(i < length)
  {
    j = !tab[i] ? i : -1;
    while(!tab[i] && i < length)
      i++;
    if(i < length && j != -1)
    {
      tab[j] = tab[i];
      tab[i] = 0;
      l--;
      i = j;
    }
    i++;
  }

  return l;
}
