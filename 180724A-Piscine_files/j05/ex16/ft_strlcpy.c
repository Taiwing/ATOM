#include "libft/libft.h"
#include "ft_strlcpy.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while (src[i] && i+1 < size)
		*dest++ = src[i++];
	while (src[i])
		i++;
	*dest = '\0';
	return (unsigned int)i;
}
