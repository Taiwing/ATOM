#include "utils.h"
#include "sort.h"

int		main(int argc, char **argv)
{
	char	**split;
	char	***next;

	if (argc == 2)
	{
		split = ft_split_whitespaces(argv[1]);
		ft_sortlen(split);
		next = next_level(split);
		ft_sort_next(next);
		ft_putnext(next);
	}
	else
		ft_putstr("\n");
	return (0);
}
