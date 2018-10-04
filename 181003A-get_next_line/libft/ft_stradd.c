#include "libft.h"

char	*ft_stradd(char **base, char *str, size_t l)
{
	char	*new;

	new = ft_strcpy(ft_strnew(ft_strlen(*base) + l + 1), *base);
	ft_strncat(new, str, l);
	ft_memdel((void **)base);
	return (new);
}

