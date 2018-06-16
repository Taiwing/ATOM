#include "libf4.h"

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	int		nb[128];
	char	*str;

	i = 1;
	size = 0;
	while (ABS(n) > 9 || i--)
	{
		nb[size++] = ABS(n) % 10;
		n = ABS(n) > 9 ? n / 10 : n;
	}
	str = ft_strnew(size + 1 + (n < 0));
	while (size--)
		str[size + (n < 0)] = 48 + nb[++i];
	str[0] = n < 0 ? '-' : str[0];
	return str;
}
