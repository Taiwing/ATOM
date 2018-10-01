#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;

	m = (unsigned char *)s;
	while (*m != (unsigned char)c && n)
	{
		n--;
		m++;
	}
	return (n ? (void *)m : NULL);
}
