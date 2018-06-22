#include "libf4.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s+ft_strlen(s);
	while (ptr != s && *ptr != c)
		ptr--;
	return (*ptr == c ? ptr : NULL);
}
