#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar(45);
	if (n / 10)
		ft_putnbr(n < 0 ? n / -10 : n / 10);
	ft_putchar(n < 0 ? 48 - (n % 10) : 48 + (n % 10));

}
