#include "libft.h"

char	*ft_strcut(char **s, size_t start, size_t l)
{
	char	*cut;

	cut = l > 0 ? ft_strsub(*s, start, l) : NULL;
	ft_memdel((void **)s);
	return (cut);
}

