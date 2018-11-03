#include "ft_itoa_cast.h"

char	*ft_itoa_base_uintmax_t(uintmax_t n, int base, int maj)
{
	static int	l = 0;
	char		*str;
	char		c;

	l++;
	c = g_bstr[maj][n % base];
	if (n / base)
		str = ft_itoa_base_uintmax_t(n / base, base, maj);
	else
	{
		str = (char *)malloc(l + 1);
		str[l] = 0;
	}
	str[--l] = c;
	if (l == 0)
		ft_strrev(str);
	return (str);
}
