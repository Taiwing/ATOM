#include <libf3.h>

int	main(int argc, char *argv[])
{
	argv++;
	while (*argv)
	{
		while (**argv)
			ft_putchar(*(*argv)++);
		ft_putchar('\n');
		argv++;
	}
}
