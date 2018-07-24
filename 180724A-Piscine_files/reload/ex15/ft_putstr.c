#include <libf3.h>

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
