#include "libft.h"

int ft_str_is_numeric(char *str)
{
  if(!str[0])
    return 1;
  else if(str[0] > 47 && str[0] < 58)
    return 1 * ft_str_is_numeric(&str[1]);
  else
    return 0;
}
