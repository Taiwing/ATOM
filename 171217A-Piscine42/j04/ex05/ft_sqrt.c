#include "libft/libft.h"
#include "ft_sqrt.h"

int ft_sqrt(int nb)
{
  int g;
  int f;

  g = nb / 2;
  f = g;

  while(1)
  {
    if(g * g == nb)
      return g;
    else if(((f * f < nb) && (g * g > nb)) || nb < 0)
      return 0;
    else if(g * g > nb)
    {
      f = g;
      g /= 2;
    }
    else if(g * g < nb)
    {
      f = g;
      g++;
    }
  }
}
