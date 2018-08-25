#include "libft/libft.h"
#include "ft_param_to_tab.h"
#include "ft_stock_par.h"

struct s_stock_par 	fill_tab(char *arg);

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *tab;

	tab = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac+1));
	tab[ac] = fill_tab(0);
	while (ac--)
		tab[ac] = fill_tab(av[ac]);
	return tab;
}

struct s_stock_par	fill_tab(char *arg)
{
	int i;
	t_stock_par elem;

	i = -1;
	while(arg && arg[++i]);
	elem.copy = (char *)malloc((i+1) * sizeof(char));
	elem.size_param = arg ? i : 0;
	elem.str = arg;
	i = 0;
	while(arg && i < elem.size_param + 1)
		elem.copy[i++] = *arg++;
	elem.tab = elem.size_param > 0 ? ft_split_whitespaces(elem.copy) : elem.tab;
	return elem;
}
