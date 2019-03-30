#include "ft_itoa_cast.h"

char	*ft_itoa_base_uint(t_uint n, int base, int maj)
{
	static int	l = 0;
	char		*str;
	char		c;
	char		bstr[] = maj ? "0123456789ABCDEF" : "0123456789abcdef";

	if (base < 2 || base > 16)
		return (0);
	l++;
	c = bstr[n % base];
	if (n / base)
		str = ft_itoa_base(n / base, base, maj);
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
