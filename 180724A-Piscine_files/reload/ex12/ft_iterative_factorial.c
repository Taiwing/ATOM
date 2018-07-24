#include <libf3.h>

/*
** great buffer overflow protection, let's remember this shit
*/

int	ft_iterative_factorial(int nb)
{
	int ret;
	int max;
	int size;

	max = 0;
	size = sizeof(int);
	ret = (nb >= 0 ? 1 : 0);
	while (size--)
		max = (max << 8) + (max == 0 ? 127 : 255);
	while (nb > 0 && ret)
		ret *= (max/ret > nb - 1 ? nb-- : 0);
	return ret;
}
