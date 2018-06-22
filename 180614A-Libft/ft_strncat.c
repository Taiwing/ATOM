#include "libf4.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t l;

	l = ft_strlen(dest);
	if (ft_memccpy((void *)dest+l, (void *)src, 0, n) == NULL)
		dest[l+n] = 0;
	return dest;
}
