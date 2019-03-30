#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		n;
	size_t		dlen;

	s = src;
	d = dest;
	n = size;
	while (n-- && *d)
		d++;
	dlen = d - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}

