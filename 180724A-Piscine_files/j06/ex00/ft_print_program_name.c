#include "libft/libft.h"

int	main(int argc, char **argv)
{
	while (*argv[0])
		ft_putchar(*argv[0]++);
	ft_putchar('\n');
	return 1;
}
