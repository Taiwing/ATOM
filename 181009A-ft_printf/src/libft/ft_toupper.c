#include "libft.h"

int	ft_toupper(int c)
{
	return (c > 96 && c < 123 ? c - 32 : c);
}
