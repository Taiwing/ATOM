#include "ft_show_tab.h"

void static	loc_putendl(char *str);
static void	ft_print_nb(int nbr);

void				ft_show_tab(struct s_stock_par *par)
{
  int j;

  while((*par).str != 0)
  {
		j = 0;
    loc_putendl((*par).str);
    ft_print_nb((*par).size_param);
    ft_putchar('\n');
    while((*par).tab[j] != 0)
      loc_putendl((*par).tab[j++]);
    par++;
  }
}

void static	loc_putendl(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

static void	ft_print_nb(int nbr)
{
	char base[] = "0123456789";

	if(nbr/10 != 0)
		ft_print_nb(nbr/10);
	ft_putchar(base[nbr%10]);
}
