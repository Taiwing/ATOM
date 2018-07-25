#include "libft/libft.h"
#include "ft_strcpy.h"

char *ft_strcpy(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src)
		*ptr++ = *src++;
	*ptr = *src;
	return dest;
}
