#include "libf4.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- && *(unsigned char *)s != (unsigned char)c)
		s++;
	return (*(unsigned char *)s == (unsigned char)c ?  (void *)s : NULL);
}
