#include "ft_utils.h"

int ft_get_num(char *str)
{
  int n[5];

  n[0] = 0;
  n[2] = ft_strlen(str) - 1;
  n[3] = n[2];

  while(n[3] >= 0)
  {
    if(str[n[3]] != '-' && ft_is_a_number(str[n[3]], n))
    {
      n[1] = str[n[3]] - 48;
      n[4] = n[2] - n[3];
      while(n[4] > 0)
      {
        n[1] *= 10;
        n[4]--;
      }
      n[0] += n[1];
    }
    else if(str[n[3]] == '-' && n[3] == 0)
      n[0] *= -1;
    n[3]--;
  }

  return n[0];
}

void ft_putnbr(int nbr)
{
  char c;

  c = '-';

  if(nbr < 0)
  {
    write(1, &c, 1);
    nbr *= -1;
  }

  c = (nbr%10)+48;

  if(!(nbr/10))
    write(1, &c, 1);
  else
  {
    ft_putnbr(nbr/10);
    write(1, &c, 1);
  }
}

int ft_strlen(char *str)
{
  int i;

  i = 0;

  while(str[i])
    i++;

  return i;
}

int ft_is_a_number(char c, int *nbr)
{
  if(c > 47 && c < 58)
    return 1;
  else
  {
    nbr[0] = 0;
    nbr[2] = nbr[3] - 1;
    return 0;
  }
}

void ft_putstr(char *str)
{
  int i;

  i = 0;

  while(str[i])
  {
    write(1, &str[i], 1);
    i++;
  }
}
