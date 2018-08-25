#include "ft_collatz_conjecture.h"

unsigned int ft_collatz_conjecture(unsigned int base)
{
  if(base == 2)
    return 1;
  else
  {
    base = base%2 ? 3*base+1 : base/2;
    return ft_collatz_conjecture(base);
  }
}
