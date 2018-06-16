#include "libf4.h"

char    **ft_strsplit(char const *s, char c)
{
	char	**split;
	char	*copy;
	size_t	size;
	size_t	l;

	size = 0;
	l = ft_strlen(s);
	copy = ft_strdup(s);
	while (l--)
	{
		copy[l] = copy[l] == c ? 0 : copy[l];
		size += copy[l] && copy[l+1] == 0 ? 1 : 0;
	}
	split = (char **)ft_memalloc((size+1) * sizeof(char *));
	l = ft_strlen(s);
	while (l--)
	{
		if ((!copy[l] && copy[l+1]) || (!l && copy[l]))
			split[--size] = ft_strdup(copy + (!l && copy[l] ? l : l+1));
	}
	free(copy);
	return split;
}
