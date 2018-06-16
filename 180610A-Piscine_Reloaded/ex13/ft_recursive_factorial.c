#include <libf3.h>

static int	intmax(void);

int 		ft_recursive_factorial(int nb)
{
	static int	limit = 0;
	int			prod;

	if (nb < 0)
		return 0;
	else if (nb == 0)
		return 1;
	else
	{
		limit = (limit == 0 ? intmax() : limit);
		prod = ft_recursive_factorial(nb-1);
		prod *= (prod != 0 && limit/prod > nb ? nb : 0);
		return prod;
	}
}

static int	intmax(void)
{
	int	max;
	int	size;

	max = 0;
	size = sizeof(int);
	while (size--)
		max = (max << 8) + (max == 0 ? 127 : 255);
	return max;
}
