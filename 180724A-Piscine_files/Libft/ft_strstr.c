#include "libf4.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*n;

	while (*haystack && *needle)
	{
		n = needle;
		while (*haystack && *n && *n == *haystack++)
			n++;
		if (*n == '\0')
			return (char *)(haystack-ft_strlen(needle));
	}
	return NULL;
}
