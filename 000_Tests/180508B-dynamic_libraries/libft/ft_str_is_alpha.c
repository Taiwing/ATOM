#include "libft.h"

int ft_str_is_alpha(char *str)
{
  if(!str[0])
    return 1;
  else if((str[0] > 64 && str[0] < 91) || (str[0] > 96 && str[0] < 123))
    return 1 * ft_str_is_alpha(&str[1]);
  else
    return 0;
}
