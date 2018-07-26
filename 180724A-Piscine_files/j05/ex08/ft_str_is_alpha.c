#include "libft/libft.h"
#include "ft_str_is_alpha.h"

int ft_str_is_alpha(char *str)
{
	if (*str == 0)
		return 1;
	else if((*str > 64 && *str < 91) || (*str > 96 && *str < 123))
		return 1 * ft_str_is_alpha(str+1);
	else
		return 0;
}
