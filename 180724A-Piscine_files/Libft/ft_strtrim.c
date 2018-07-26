#include "libf4.h"

char	*ft_strtrim(char const *s)
{
	size_t	sz;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	sz = *s ? ft_strlen(s) - 1 : 0;
	while (s[sz] == ' ' || s[sz] == '\n' || s[sz] == '\t')
		sz--;
	return ft_strsub(s, 0, sz+1);
}
