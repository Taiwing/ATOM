#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		dlen;

	s = src;
	d = dst;
	while (size-- && *d)
		d++;
	dlen = d - dst;
	if (size == 0)
		return (dlen + ft_strlen(src));
	while (*s)
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}
