#include "libft/libft.h"
#include "ft_strlowcase.h"

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = str[i] > 64 && str[i] < 91 ? str[i] + 32 : str[i];
	return str;
}
