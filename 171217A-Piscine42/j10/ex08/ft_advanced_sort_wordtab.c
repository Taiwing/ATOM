#include "ft_advanced_sort_wordtab.h"

void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
  int i;
  int j;
  char *ptr;

  i = 0;

  while(tab[i])
  {
    j = i;
    while(tab[j])
    {
      if((*cmp)(tab[i], tab[j]) > 0)
      {
        ptr = tab[i];
        tab[i] = tab[j];
        tab[j] = ptr;
      }
      j++;
    }
    i++;
  }
}
