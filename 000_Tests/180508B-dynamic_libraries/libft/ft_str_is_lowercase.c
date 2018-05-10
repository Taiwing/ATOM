#include "libft.h"

int ft_str_is_lowercase(char *str)
{
  if(!str[0])
    return 1;
  else if((str[0] > 47 && str[0] < 58) || (str[0] > 96 && str[0] < 123))
    return 1 * ft_str_is_lowercase(&str[1]);
  else
    return 0;
}
