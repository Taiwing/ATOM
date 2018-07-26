#include "libft/libft.h"
#include "ft_strlcat.h"

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	l[3];

	l[0] = -1;
	while (dest[++l[0]]);
	l[1] = -1;
	while (src[++l[1]]);
	l[2] = (int)size;
	while (*src && l[2]--)
		*((dest++) + l[0]) = *src++;
	*dest = l[2] > 0 ? '\0': *dest;
	return (unsigned int)(l[0]+l[1]);
}

