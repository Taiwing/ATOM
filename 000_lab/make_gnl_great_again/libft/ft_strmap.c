#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		l;
	char	*map;

	l = ft_strlen(s);
	map = ft_strnew(l + 1);
	while (l--)
		map[l] = f(s[l]);
	return (map);	
}
