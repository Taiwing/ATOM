#include "ft_get_arguments.h"

int ft_get_arguments(int *C, int *fc, char **fv, char **av)
{
  int i;
  int ac;

  i = 1;
  ac = *fc;
  *fc = 0;

  while(i < ac)
  {
    if(ft_is_C_option(av[i]))
      *C = 1;
    else
    {
      if(!ft_does_file_exist(av[i]))
        return 0;
      fv[(*fc)] = av[i];
      (*fc)++;
    }
    i++;
  }

  return 1;
}

int ft_is_C_option(char *str)
{
  int i;

  i = 0;

  while(str[i])
    i++;

  if(i == 2 && str[0] == '-' && str[1] == 'C')
    return 1;
  else
    return 0;
}

int ft_does_file_exist(char *file)
{
  int fd;

  fd = open(file, O_RDONLY);
  close(fd);

  if(fd < 0)
    return 0;
  else
    return 1;
}
