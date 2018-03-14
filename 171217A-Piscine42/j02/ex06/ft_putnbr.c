#include "ft_putnbr.h"

void ft_putnbr(int nb)
{
  if(nb < 0)
  {
    printf("-");
    nb *= -1;
  }

  int l;
  int i;

  l = ft_get_length(nb);
  i = 0;

  while(i < l)
  {
    printf("%c", ft_get_char(nb, l, i));
    i++;
  }

  printf("\n");
}

int ft_get_length(int nb)
{
  if(nb > 999999999) /*if nb is more than 9 digits long*/
    return 10;
  else if(nb > 99999999)
    return 9;
  else if(nb > 9999999)
    return 8;
  else if(nb > 999999)
    return 7;
  else if(nb > 99999)
    return 6;
  else if(nb > 9999)
    return 5;
  else if(nb > 999)
    return 4;
  else if(nb > 99)
    return 3;
  else if(nb > 9)
    return 2;
  else
    return 1;
}

char ft_get_char(int nb, int length, int charPos)
{
  int i;

  i = length - charPos;

  while(i > 1)
  {
    nb /= 10;
    i--;
  }

  return 48 + (nb % 10);
}
