#include "ft_is_sort.h"

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
  int i;
  int ret;
  int test;

  i = 0;
  test = 0;

  while(i < length-1)
  {
    ret = (*f)(tab[i], tab[i+1]);
    test = ret && !test ? ret/ft_abs(ret) : test;

    if((test < 0 && ret > 0) || (test > 0 && ret < 0))
      return 0;

    i++;
  }

  return 1;
}

int ft_nbrcmp(int a, int b)
{
  return a-b;
}
