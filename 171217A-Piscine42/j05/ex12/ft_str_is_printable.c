#include "libft/libft.h"
#include "ft_str_is_printable.h"

int ft_str_is_printable(char *str)
{
  if(!str[0])
    return 1;
  else if(str[0] > 31 && str[0] < 127)
    return 1 * ft_str_is_printable(&str[1]);
  else
    return 0;
}
