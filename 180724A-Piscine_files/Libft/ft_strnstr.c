#include "libf4.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	const char	*n;

	i = 0;
	while (haystack[i] && *needle && i < len)
	{
		n = needle;
		while (haystack[i] && *n && *n == haystack[i++] && i-1 < len)
			n++;
		if (*n == '\0')
			return (char *)(haystack+i-ft_strlen(needle));
	}
	return NULL;
}
