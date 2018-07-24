#include "libft/libft.h"
#include "ft_find_next_prime.h"

int ft_find_next_prime(int nb)
{
  int i;

  i = (nb % 2 == 0) ? nb + 1 : nb + 2;

  while(1)
  {
    if(ft_is_prime(i))
      return i;
    i += 2;
  }
}

int ft_is_prime(int nb)
{
  if(nb <= 1)
   return 0;
  else if(nb <= 3)
   return 1;
  else if(nb % 2 == 0 || nb % 3 == 0)
   return 0;

  int i;

  i = 5;

  while(i * i <= nb)
  {
    if(nb % i == 0 || nb % (i + 2) == 0)
      return 0;
    i += 6;
  }

  return 1;
}
