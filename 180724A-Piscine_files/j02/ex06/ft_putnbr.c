#include "ft_putnbr.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		printf("-");
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	printf("%c", 48 + (n % 10));
}
