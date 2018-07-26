#include "libft/libft.h"
#include "ft_strupcase.h"

char	*ft_strupcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = str[i] > 96 && str[i] < 123 ? str[i] - 32 : str[i];
	return str;
}
