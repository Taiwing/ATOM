#include "libf4.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = ft_strnew(len+1);
	while (len--)
		sub[len] = s[start+len];
	return sub;
}
