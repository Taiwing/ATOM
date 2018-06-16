#include "libf4.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*ptr;

	join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ptr = join;
	while (*s1 || *s2)
		*ptr++ = (*s1 ? *s1++ : *s2++);
	return join;
}
