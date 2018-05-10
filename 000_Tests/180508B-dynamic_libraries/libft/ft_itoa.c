#include "libft.h"

static void ft_convert_nb(int nbr, char *str, int b);
static char ft_get_char(int nbr);

void ft_itoa(int nbr, char *str, int b)
{
  int i;

  i = 0;

  if(b <= 1)
    return;
  else
  {
    if(nbr < 0)
    {
      str[i] = '-';
      nbr *= -1;
      i++;
    }
    ft_convert_nb(nbr, &str[i], b);
    ft_strrev(&str[i]);
  }
}

static void ft_convert_nb(int nbr, char *str, int b)
{
  if(nbr/b == 0)
  {
    str[0] = ft_get_char(nbr%b);
    str[1] = '\0';
  }
  else
  {
    str[0] = ft_get_char(nbr%b);
    ft_convert_nb(nbr/b, &str[1], b);
  }
}

static char ft_get_char(int nbr)
{
  return nbr<10 ? nbr+48 : nbr+65;
}
