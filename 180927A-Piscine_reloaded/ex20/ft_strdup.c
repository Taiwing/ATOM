#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		l;
	char	*dup;

	l = -1;
	while (src && src[++l])
		;
	if (!src || !(dup = malloc(l + 1)))
		return (NULL);
	while (l-- > -1)
		dup[l + 1] = src[l + 1];
	return (dup);
}
