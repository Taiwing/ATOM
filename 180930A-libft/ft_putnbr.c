#include "libft.h"

void	ft_putnbr(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd(45, fd);
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n < 0 ? 48 - (n % 10) : 48 + (n % 10), fd);

}
