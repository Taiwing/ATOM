#include "libf4.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return dest;
}
