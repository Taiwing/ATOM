#include "libft.h"

char	*ft_strdup(const char *s)
{
	return (ft_strcpy(ft_strnew(ft_strlen(s) + 1), s));
}
