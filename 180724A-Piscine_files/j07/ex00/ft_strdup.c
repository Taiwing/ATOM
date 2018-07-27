#include "ft_strdup.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i++]);
	dup = (char *)malloc(i * sizeof(char));
	while (i--)
		dup[i] = src[i];
	return dup;
}
