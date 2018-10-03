#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (s && *s && *s != c)
		s++;
	return (s && *s == c ? (char *)s : NULL);
}
