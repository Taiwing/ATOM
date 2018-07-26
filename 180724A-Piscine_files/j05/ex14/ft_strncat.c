#include "libft/libft.h"
#include "ft_strncat.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src && nb--)
		*ptr++ = *src++;
	*ptr = '\0';
	return dest;
}
