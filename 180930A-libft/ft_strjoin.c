#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	return (ft_strcat(ft_strcpy(ft_strnew(size), s1), s2));
}
