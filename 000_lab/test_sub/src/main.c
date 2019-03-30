#include "ft_printf.h"

int		main(int argc, char **argv)
{
	ft_printf("argv:\n%#*t%s\n", argc - 1, ++argv);
	return (0);
}
