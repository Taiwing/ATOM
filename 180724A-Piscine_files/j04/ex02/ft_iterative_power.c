#include "libft/libft.h"
#include "ft_iterative_power.h"

int ft_iterative_power(int nb, int power)
{
	int iter;

	if(power < 0)
		return 0;
	else
	{
		iter = 1;
		while(power--)
			iter *= nb;
		return iter;
	}
}
