#include "libft/libft.h"

int	main(int argc, char **argv)
{
	while (*++argv)
	{
		while (**argv)
			ft_putchar(*(*argv)++);
		ft_putchar('\n');
	}
	return 1;
}
