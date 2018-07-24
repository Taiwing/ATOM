#include "ft_show_tab.h"

void static ft_loc_putstr(char *str);
static void ft_print_nb(int nbr);

void ft_show_tab(struct s_stock_par *par)
{
  int i;
  int j;

  i = 0;

  while(par[i].str != 0)
  {
    ft_loc_putstr(par[i].str);
    ft_putchar('\n');
    ft_print_nb(par[i].size_param);
    ft_putchar('\n');

    j = 0;
    while(par[i].tab[j] != 0)
    {
      ft_loc_putstr(par[i].tab[j]);
      ft_putchar('\n');
      j++;
    }
    i++;
  }
}

void static ft_loc_putstr(char *str)
{
  int i;

  i = 0;

  while(str[i])
  {
    ft_putchar(str[i]);
    i++;
  }
}

static void ft_print_nb(int nbr)
{
  char base[] = "0123456789";

  if(nbr/10 == 0)
    ft_putchar(base[nbr%10]);
  else
  {
    ft_print_nb(nbr/10);
    ft_putchar(base[nbr%10]);
  }
}
