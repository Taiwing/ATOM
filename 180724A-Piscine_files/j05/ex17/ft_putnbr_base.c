#include "libft/libft.h"
#include "ft_putnbr_base.h"

static int ft_is_base_valid(char *base);
static void ft_print_nb(int nbr, char *base, int b);

void ft_putnbr_base(int nbr, char *base)
{
  int b;

  b = ft_is_base_valid(base);

  if(!b)
    return;
  else
  {
    if(nbr < 0)
    {
      ft_putchar('-');
      nbr *= -1;
    }
    ft_print_nb(nbr, base, b);
    ft_putchar('\n');
  }
}

static int ft_is_base_valid(char *base)
{
  int b;
  int i;
  int err;

  b = 0;
  i = 0;
  err = 0;

  while(base[b] && !err)
  {
    i = 0;
    while(i <= b && !err)
    {
      err = (base[i]==base[b] && i!=b) || base[i]==43 || base[i]==45 ? 1 : 0;
      i++;
    }
    b++;
  }

  if(b <= 1 || err)
    return 0;
  else
    return b;
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
