#include "libft/libft.h"
#include "ft_sort_integer_table.h"

void ft_sort_integer_table(int *tab, int size)
{
  int i;
  int min;

  i = 0;

  while(i < size)
  {
    if(i != ft_get_min_pos(tab, size, i))
    {
      min = tab[ft_get_min_pos(tab, size, i)];
      tab[ft_get_min_pos(tab, size, i)] = tab[i];
      tab[i] = min;
    }
    i++;
  }
}

int ft_get_min_pos(int *tab, int size, int i)
{
  int pos;

  pos = i;

  while(i < size)
  {
    if(tab[i] < tab[pos])
      pos = i;
    i++;
  }

  return pos;
}
