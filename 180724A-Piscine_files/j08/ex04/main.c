#include "libft/libft.h"
#include "ft_param_to_tab.h"
#include "ft_stock_par.h"

int	main(int argc, char **argv)
{
	t_stock_par *tab;

	tab = ft_param_to_tab(argc, argv);
	ft_show_tab(tab);
	return 0;
}
