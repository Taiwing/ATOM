#include "libf4.h"

void	ft_striter(char *s, void (*f)(char *))
{
	while (*s)
		(*f)(s++);
}
