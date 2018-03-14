#include "params.h"

int get_params(char **name, int *num_layers, int *sizes, char *av[])
{
  int ret;
  int ac = *num_layers;
  *num_layers = 0;

  for(int i = 1; i < ac; i++)
  {
    *name = i == 1 && av[i][0] != '-' ? av[i] : *name;
    if(!ft_strcmp(av[i], "-l"))
      *num_layers = ft_atoi(av[i+1]);
    else if(!ft_strcmp(av[i], "-s"))
    {
      sizes = (int *)malloc((*num_layers) * sizeof(int));
      for(int j = i+1; (j-(i+1)) < (*num_layers); j++)
        sizes[j-(i+1)] = j < ac ? ft_atoi(av[j]) : 0;
    }
  }

  ret = param_error(*name, *num_layers, sizes);
  if(ret == 2)
  {
    create_conf(get_conf_name(*name), *num_layers, sizes);
    free(sizes);
    return 1;
  }
  else
    return !ret;
}

int param_error(char *name, int num_layers, int *sizes)
{
  int err_w = 0;
  int conf = 0;

  for(int i = 0; i < num_layers && sizes; i++)
    err_w = sizes[i] < 10000 && sizes[i] > 0 ? err_w : 1;

  if(!name || ((num_layers < 3 || num_layers > 100000) && sizes) || err_w)
    return 1;
  else if(!sizes && !(conf = does_config_exist(name)))
    return 1;
  else if(sizes && !conf)
    return 2;
  else
    return 0;
}
