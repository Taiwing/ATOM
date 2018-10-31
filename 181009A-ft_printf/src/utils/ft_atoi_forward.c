#include "ft_atoi_forward.h"

int		ft_atoi_forward(char **nptr)
{
	int		nb;
	int		sign;
	char	*str;

	nb = 0;
	sign = 1;
	str = *nptr;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : sign;
	while (*str && *str > 47 && *str < 58)
		nb = (nb * 10) + ((*str++) - 48);
	*nptr = str;
	return (nb * sign);
}
