#include "libft/libft.h"
#include "ft_iterative_factorial.h"

int ft_iterative_factorial(int nb)
{
  if(nb < 0 || nb > 12)
    return 0;
  else if(nb == 0)
    return 1;
  else
  {
    int i;
    int fact;

    i = 1;
    fact = 1;

    while(i <= nb)
    {
      fact *= i;
      i++;
    }

    return fact;
  }
}
