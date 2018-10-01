#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*d;

	d = ft_strchr(dest, 0);
	while (n-- && *src)
		*d++ = *src++;
	*d = 0;
	return (dest);
}
