#include "libft/libft.h"
#include "ft_putstr.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
