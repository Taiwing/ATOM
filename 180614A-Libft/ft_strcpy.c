#include "libf4.h"

char	*ft_strcpy(char *dest, const char *src)
{
	return (char *)ft_memcpy((void *)dest, (void *)src, ft_strlen(src)+1);
}
