#include "libft/libft.h"
#include "ft_strncpy.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i++ < n)
		dest[i-1] = src[i-1] ? src[i-1] : '\0';
	return dest;
}
