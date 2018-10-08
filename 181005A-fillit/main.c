#include "main.h"
#include "libft.h"

#include <stdio.h> /*TEST*/

void	print_square(int l, char **square)
{
	int	i;
	int	j;

	j = -1;
	while(++j < l)
	{
		i = -1;
		while (++i < l)
			ft_putchar(square[i][j]);
		ft_putchar(10);
	}
}

int	main(int argc, char **argv)
{
	int		l;
	int		tc;
	int		*tetros;
	char	**square;

	if (argc != 2)	
	{
		ft_putstr("usage: fillit FILE\n");
		return (1);
	}
	tc = get_tetros(argv[1], &tetros);
	printf("tc = %d\nlist: ", tc);
	for (int i = 0; i < tc; i++)
		printf("%d%s", tetros[i], i < tc - 1 ? ", " : "\n");
	l = get_square(tc, tetros, &square);
	print_square(l, square);
	free(square);
	return (0);
}
