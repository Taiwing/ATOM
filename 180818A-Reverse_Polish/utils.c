#include "utils.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar(45);
	if (nb > 9 || nb < -9)
		ft_putnbr(nb < 0 ? nb / -10 : nb / 10);
	ft_putchar(nb < 0 ? ((nb % -10) * -1) + 48 : (nb % 10) + 48);
}

int ft_atoi(char **str)
{
	int nb;
	char *ptr;

	nb = 0;
	ptr = *str;
	while (*ptr > 48 && *ptr < 58)
		nb = (nb * 10) + (*ptr++ - 48);
	*str = ptr;
	return nb;
}
