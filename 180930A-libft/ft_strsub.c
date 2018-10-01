#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	return (ft_strncpy(ft_strnew(len + 1), s + start, len));
}
