#include "libft.h"

char	*ft_strcpy(char *d, const char *s)
{
	return ((char *)ft_memcpy((void *)d, (const void *)s, ft_strlen(s) + 1));
}
