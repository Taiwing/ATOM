#include "ft_itoa_cast.h"

char	*ft_itoa_shint(t_shint n)
{
	int		i;
	int		size;
	int		sign;
	int		nb[128];
	char	*str;

	size = 0;
	sign = (n < 0);
	while (n || !size)
	{
		nb[size++] = sign ? (n % 10) * -1 : n % 10;
		n /= 10;
	}
	str = ft_strnew(size + 1 + sign);
	i = 0;
	while (size--)
		str[size + sign] = 48 + nb[i++];
	str[0] = sign ? '-' : str[0];
	return (str);
}

