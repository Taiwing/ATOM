#include "libft.h"

void	ft_strclr(char *s)
{
	ft_bzero((void *)s, ft_strlen(s));
}
