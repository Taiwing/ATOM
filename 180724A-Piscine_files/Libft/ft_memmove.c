#include "libf4.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*buf;

	buf = ft_memcpy(malloc(n), src, n);
	ft_memcpy(dest, buf, n);
	free(buf);
	return dest;
}
