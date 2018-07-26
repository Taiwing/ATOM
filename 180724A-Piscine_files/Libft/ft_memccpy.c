#include "libf4.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(char *)dest++ = *(char *)src;
		if (*(char *)src == c)
			return dest;
		else
			src++;
	}
	return NULL;
}
