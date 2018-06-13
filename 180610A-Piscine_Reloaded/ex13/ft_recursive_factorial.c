#include <libf3.h>

int	ft_recursive_factorial(int nb)
{
	int ret;

	if (nb < 0)
		ret = 0;
	else
		ret = (nb == 0 ? 1 : ft_recursive_factorial(nb-1));

	if (ret == 0 || ret == 1)
		return ret;
	else
		return (2147483647/ret > nb ? ret * nb : 0);
}
