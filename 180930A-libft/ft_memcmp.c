#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char   *c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n-- && *c1 == *c2)
	{
		c1++;
		c2++;
	}
	return ((int)(*c1 - *c2));
}
