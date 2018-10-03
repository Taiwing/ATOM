#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == c)
			return ((void *)d);
	}
	return (NULL);
}
