#include "ft_putchar.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
