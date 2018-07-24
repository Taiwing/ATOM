#include "ft_scrambler.h"

void ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
  int e;

  e = *******c;
  *******c = ***a;
  ***a = e;

  e = ****d;
  ****d = ***a;
  ***a = e;

  e = *b;
  *b = ***a;
  ***a = e;
}
