#include "libf4.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t sz;

	sz = ft_strlen(src)+1;
	ft_bzero((void *)dest, (sz < n ? n : 0));
	return (char *)ft_memcpy((void *)dest, (void *)src, (sz < n ? sz : n));
}
