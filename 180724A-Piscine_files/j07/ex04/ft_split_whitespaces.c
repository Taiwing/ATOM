#include "ft_split_whitespaces.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	cutstr(char *str, char ***split, int size);

char		**ft_split_whitespaces(char *str)
{
	char	**split;

	split = NULL;
	cutstr(str, &split, 0);
	return split;
}

static void	cutstr(char *str, char ***split, int size)
{
	int		i;
	char	*ptr;

	ptr = 0;
	while (*str && (*str == 9 || *str == 10 || *str == 32))
		str++;
	if (*str)
	{
		i = 0;
		while (str[i] && str[i] != 9 && str[i] != 10 && str[i] != 32)
			i++;
		ptr = (char *)malloc((i+1) * sizeof(char));
		i = 0;
		while (*str && *str != 9 && *str != 10 && *str != 32)
			ptr[i++] = *str++;
		ptr[i] = '\0';
		cutstr(str, split, size+1);
	}
	else
		*split = (char **)malloc((size+1) * sizeof(char *));
	(*split)[size] = ptr;
}
