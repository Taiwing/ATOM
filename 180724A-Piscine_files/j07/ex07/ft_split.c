#include "libft/libft.h"
#include "ft_split.h"
#include <stdlib.h>

static void	cutstr(char *str, char ***split, int size, char *charset);
static int	is_sepchar(char c, char *charset);

char **ft_split(char *str, char *charset)
{
	char	**split;

	split = NULL;
	cutstr(str, &split, 0, charset);
	return split;
}

static void	cutstr(char *str, char ***split, int size, char *charset)
{
	int		i;
	char	*ptr;

	ptr = 0;
	while (*str && is_sepchar(*str, charset))
		str++;
	if (*str)
	{
		i = 0;
		while (str[i] && str[i] != 9 && str[i] != 10 && str[i] != 32)
			i++;
		ptr = (char *)malloc((i+1) * sizeof(char));
		i = 0;
		while (*str && !is_sepchar(*str, charset))
			ptr[i++] = *str++;
		ptr[i] = '\0';
		cutstr(str, split, size+1, charset);
	}
	else
		*split = (char **)malloc((size+1) * sizeof(char *));
	(*split)[size] = ptr;
}

static int	is_sepchar(char c, char *charset)
{
	while (*charset && *charset != c)
		charset++;
	return *charset;
}
