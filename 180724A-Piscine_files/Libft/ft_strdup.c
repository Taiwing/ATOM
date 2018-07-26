#include "libf4.h"

char	*ft_strdup(const char *s)
{
	return ft_strsub(s, 0, ft_strlen(s));
}
