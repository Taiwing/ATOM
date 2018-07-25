#include "libft/libft.h"
#include "ft_iterative_factorial.h"

int ft_iterative_factorial(int nb)
{
	int fact;

	if(nb < 0 || nb > 12)
		return 0;
	else
	{
		fact = 1;
		while(nb)
			fact *= nb--;
		return fact;
	}
}
