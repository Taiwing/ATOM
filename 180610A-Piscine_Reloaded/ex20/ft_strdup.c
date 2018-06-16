#include <libf3.h>

char	*ft_strdup(char *src)
{
	int		c;
	char	*dest;

	c = 0;
	while (src[c])
		c++;
	dest = (char *)malloc(++c);
	while (c-- > 0)
		dest[c] = src[c];
	return dest;
}
