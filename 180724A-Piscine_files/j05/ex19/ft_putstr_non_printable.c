#include "libft/libft.h"
#include "ft_putstr_non_printable.h"

void ft_putstr_non_printable(char *str)
{
  if(!str[0])
    return;
  else if(str[0] > 31 && str[0] < 127)
    ft_putchar(str[0]);
  else
  {
    ft_putchar(92);
    if(str[0] < 16)
      ft_putchar('0');
    ft_putnbr_base((int)str[0], "0123456789abcdef");
  }
  ft_putstr_non_printable(&str[1]);
}
