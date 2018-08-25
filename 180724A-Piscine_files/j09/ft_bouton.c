#include "ft_bouton.h"

int ft_bouton(int i, int j, int k)
{
  if((i > j && i < k) || (i > k && i < j))
    return i;
  if((j > i && j < k) || (j > k && j < i))
    return j;
  if((k > i && k < j) || (k > j && k < i))
    return k;

  return 0;
}
