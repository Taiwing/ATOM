#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
		ret = *s++ == c ? (char *)s - 1 : ret;
	return (c ? ret : (char *)s);
}
