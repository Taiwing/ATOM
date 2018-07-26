#include "libf4.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	size;

	size = ft_strlen(s);
	map = ft_strnew(size + 1);
	while (size--)
		map[size] = (*f)(size, s[size]);
	return map;
}
