//#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char		c;
	char		*s;
	static int	i = 0;
	static int	l = 0;

	i += i < 0 || n < 0 ? -1 : 1;
	if (i == -1)
		c = 45;
	else
		c = n < 0 ? 48 - (n % 10) : (n % 10) + 48;
	s = n / 10 ? ft_itoa(n / 10) : ft_strnew(i < 0 ? (i * -1) + 1 : i + 1);
	if (n / 10 == 0)
		l = i < 0 ? i * -1 : i;
	if (c == 45 || c == 0)
		s[i < 0 ? (i + 1) * -1 : i - 1] = c;
	else
		s[i < 0 ? l + i - 1 : l - i] = c;
	i += i < 0 ? 1 : -1;
	return (s);
}
