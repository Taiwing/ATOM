#include "libft.h"

char	*ft_strncpy(char *d, const char *s, size_t n)
{
	char	*dest;

	dest = d;
	while (n && *s)
	{
		*d++ = *s++;
		n--;
	}
	ft_bzero(d, n);
	return (dest);	
}
