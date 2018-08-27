#include <stdlib.h>

void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	i--;
	while (i > j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i--;
		j++;	
	}
}

char	*ft_itoa_base(int value, int base)
{
	static int	l = 0;
	char		*str;
	char		c;
	char		bstr[] = "0123456789ABCDEF";

	if (base < 2 || base > 16)
		return (0);
	l++;
	if (base == 10 && l == 1)
		c = value < 0 ? 45 : bstr[value % base];
	else
		c = bstr[value < 0 ? (value % -base) * -1 : value % base];
	if ((value / base || value % base) && value < 0 && l == 1 && base == 10)
		str = ft_itoa_base(value, base);
	else if (value / base)
		str = ft_itoa_base(value < 0 ? value / -base : value / base, base);
	else
	{
		str = (char *)malloc(l + 1);
		str[l] = 0;
	}
	str[--l] = c;
	if (l == 0)
		ft_strrev(str[0] == 45 ? str + 1 : str);
	return (str);
}
