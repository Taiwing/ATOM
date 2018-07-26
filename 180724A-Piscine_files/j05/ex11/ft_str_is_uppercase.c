#include "libft/libft.h"
#include "ft_str_is_uppercase.h"

int ft_str_is_uppercase(char *str)
{
	if (*str == 0)
		return 1;
	else if ((*str > 47 && *str < 58) || (*str > 64 && *str < 91))
		return 1 * ft_str_is_uppercase(str+1);
	else
		return 0;
}
