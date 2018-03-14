#include "ft_putnbr.h"

static void ft_print_nb(int nbr);

void ft_putnbr(int nbr)
{
  char c;

  c = '-';

  if(nbr < 0)
  {
    write(1, &c, 1);
    nbr *= -1;
  }

  ft_print_nb(nbr);
}

static void ft_print_nb(int nbr)
{
  char c;

  c = (nbr%10)+48;

  if(!(nbr/10))
    write(1, &c, 1);
  else
  {
    ft_print_nb(nbr/10);
    write(1, &c, 1);
  }
}
