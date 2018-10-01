#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	l;

	while (*s == 32 || (*s > 8 && *s < 11))
		s++;
	l = 0;
	while (s[l] && !(s[l] == 32 || (s[l] > 8 && s[l] < 11)))
		l++;
	return (ft_strncpy(ft_strnew(l + 1), s, l));
}
