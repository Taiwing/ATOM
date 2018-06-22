#include "libf4.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return (*s == c ? (char *)s : NULL);
}
