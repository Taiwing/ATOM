#include "libft/libft.h"
#include "ft_param_to_tab.h"
#include "ft_stock_par.h"

struct s_stock_par ft_fill_tab(char *arg);

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
  int i;
  t_stock_par *tab;

  i = 0;
  tab = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac+1));

  while(i < ac+1)
  {
    tab[i] = i == ac ? ft_fill_tab(0) : ft_fill_tab(av[i]);
    i++;
  }

  return tab;
}

struct s_stock_par ft_fill_tab(char *arg)
{
  int i;
  t_stock_par elem;

  i = 0;

  while(arg && arg[i])
    i++;

  elem.copy = (char *)malloc(i);
  elem.size_param = i;
  i = 0;

  while(i < elem.size_param && elem.size_param)
  {
    elem.copy[i] = arg[i];
    i++;
  }

  elem.str = arg;
  elem.tab = elem.size_param ? ft_split_whitespaces(elem.copy) : elem.tab;
  elem.size_param--;

  return elem;
}
