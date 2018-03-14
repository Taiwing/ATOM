#include "ft_get_arguments.h"

int ft_get_arguments(int *c, int *fc, char **fv, char **argv)
{
  int i;
  int ac;

  i = 1;
  ac = *fc;
  *fc = 0;

  while(i < ac)
  {
    if(ft_is_c_option(argv[i]))
    {
      if((i+1) >= ac || !ft_is_numeric(argv[i+1]))
        return 0;
      *c = ft_atoi(argv[i+1]);
      i++;
    }
    else
    {
      fv[(*fc)] = argv[i];
      (*fc)++;
    }
    i++;
  }

  return 1;
}

int ft_is_c_option(char *str)
{
  int i;

  i = 0;

  while(str[i])
    i++;

  if(i == 2 && str[0] == '-' && str[1] == 'c')
    return 1;
  else
    return 0;
}

int ft_is_numeric(char *str)
{
  if(!str[0])
    return 1;
  else if(str[0] > 47 && str[0] < 58)
    return 1 * ft_is_numeric(&str[1]);
  else
    return 0;
}

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

int ft_strlen(char *str)
{
  int i;

  i = 0;

  while(str[i])
    i++;

  return i;
}
