#include <libf3.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
