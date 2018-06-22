#include "libf4.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n && *(unsigned char *)s != (unsigned char)c)
		s += (--n ? 1 : 0);
	return (*(unsigned char *)s == (unsigned char)c && n ? (void *)s : NULL);
}
