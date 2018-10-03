#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	ft_memcpy((void *)ft_strchr(dest, 0), (const void *)src, ft_strlen(src) + 1);
	return (dest);
}
