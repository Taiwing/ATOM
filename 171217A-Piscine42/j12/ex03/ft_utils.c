#include "ft_utils.h"

static void ft_print_nb(int nbr, char *base, int b);

int ft_pow(int a, int b)
{
  if(!b)
    return 1;
  else
    return a * ft_pow(a, b-1);
}

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putstr(char *str)
{
  int i;

  i = 0;

  while(str[i] != '\0')
  {
    ft_putchar(str[i]);
    i++;
  }
}

void ft_putnbr_base(int nbr, char *base)
{
  if(nbr < 0)
  {
    ft_putchar('-');
    nbr *= -1;
  }
  ft_print_nb(nbr, base, 16);
}

static void ft_print_nb(int nbr, char *base, int b)
{
  if(nbr/b == 0)
    ft_putchar(base[nbr%b]);
  else
  {
    ft_print_nb(nbr/b, base, b);
    ft_putchar(base[nbr%b]);
  }
}
