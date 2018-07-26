#include "libf4.h"

int	ft_atoi(const char *nptr)
{
	int nb;
	int sign;

	sign = *nptr == '-' ? -1 : 1;
	nb = sign < 0 ? ((*++nptr) - 48) : ((*nptr) - 48);
	while (*++nptr)
		nb = (nb * 10) + ((*nptr) - 48);
	return (nb * sign);
}
