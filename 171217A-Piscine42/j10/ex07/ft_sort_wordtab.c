#include "ft_sort_wordtab.h"

static int ft_loc_strcmp(char *s1, char *s2);

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
      if(ft_loc_strcmp(tab[i], tab[j]) > 0)
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

static int ft_loc_strcmp(char *s1, char *s2)
{
  if(s1[0] == 0 || s2[0] == 0 || (s1[0] - s2[0] != 0))
    return s1[0] - s2[0];
  else
    return s1[0] - s2[0] + ft_loc_strcmp(&s1[1], &s2[1]);
}
