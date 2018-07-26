#include "libf4.h"

int	ft_strequ(char const *s1, char const *s2)
{
	return (*s1 == *s2 && *s1 && *s2 ? ft_strequ(s1+1, s2+1) : *s1 == *s2);
}
