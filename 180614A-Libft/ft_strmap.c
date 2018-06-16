#include "libf4.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	size_t	size;

	size = ft_strlen(s);
	map = ft_strnew(size + 1);
	while (*s)
		*map++ = (*f)(*s++);
	return map-size;
}
