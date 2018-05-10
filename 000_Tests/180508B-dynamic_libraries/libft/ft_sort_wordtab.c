#include "libft.h"

void ft_sort_wordtab(char **tab)
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
      if(ft_strcmp(tab[i], tab[j]) > 0)
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
