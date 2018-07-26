#include "libf4.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (*s1 == *s2 && *s1 && *s2 && n > 1)
		return ft_strnequ(s1+1, s2+1, n-1);
	else
		return (n ? *s1 == *s2 : 0);
}
