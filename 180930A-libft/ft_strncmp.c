#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (*s1 && *s2 && *s1 == *s2 && n)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	else
		return (*s1 - *s2);
}
