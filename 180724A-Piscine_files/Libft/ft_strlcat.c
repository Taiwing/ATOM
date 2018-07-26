#include "libf4.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(dest);
	while (i++ < size && src[i-1])
		dest[l+i-1] = src[i-1];
	dest[l+i-1] = i-1 < size ? 0 : dest[l+i-1];
	return ft_strlen(src)+l;
}

