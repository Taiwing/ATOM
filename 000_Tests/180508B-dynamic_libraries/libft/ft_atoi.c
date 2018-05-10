#include "libft.h"

int ft_atoi(char *str)
{
  int n[5];

  n[0] = 0;
  n[2] = ft_strlen(str) - 1;
  n[3] = n[2];

  while(n[3] >= 0)
  {
    if(str[n[3]] != '-')
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
    else
      n[0] *= -1;
    n[3]--;
  }

  return n[0];
}
