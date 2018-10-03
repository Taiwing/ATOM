#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	else if (*s1 != *s2 || *s1 == 0 || *s2 == 0)
		return (*s1 - *s2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
