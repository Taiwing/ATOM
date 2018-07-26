#include "ft_strstr.h"

char	*ft_strstr(char *str, char *to_find)
{
	char	*n;
	char	*start;

	while (*str && *to_find)
	{
		n = to_find;
		start = str;
		while (*str && *n && *n == *str++)
			n++;
		if (*n == '\0')
			return start;
	}
	return NULL;
}
