#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign = *nptr++ == '-' ? -1 : sign;
	while (*nptr && *nptr > 47 && *nptr < 58)
		nb = (nb * 10) + ((*nptr++) - 48);
	return (nb * sign);
}

