#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	i = 0;
	map = ft_strnew(ft_strlen(s) + 1);
	while (s[i++])
		map[i - 1] = f(i - 1, s[i - 1]);
	return (map);
}
