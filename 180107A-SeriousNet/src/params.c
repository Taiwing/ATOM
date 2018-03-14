#include "params.h"

char *get_params(int ac, char *av[], int param_arr[4])
{
  int ret;
  int num_layers = 0;
  int *sizes = NULL;
  char *actf = NULL;
  char *name = NULL;

  for(int i = 1; i < ac; i++)
  {
    name = i == 1 && av[i][0] != '-' ? av[i] : name;
    if(!ft_strcmp(av[i], "-l"))
      num_layers = i < ac-1 ? ft_atoi(av[i+1]) : num_layers;
    else if(!ft_strcmp(av[i], "-s"))
    {
      sizes = (int *)malloc((num_layers) * sizeof(int));
      for(int j = i+1; (j-(i+1)) < (num_layers); j++)
        sizes[j-(i+1)] = j < ac ? ft_atoi(av[j]) : 0;
    }
    else if(!ft_strcmp(av[i], "-f"))
      actf = i < ac-1 ? av[i+1] : actf;
    else if(!ft_strcmp(av[i], "-p"))
      param_arr[0] = 1;
    else if(!ft_strcmp(av[i], "-e"))
      param_arr[1] = 1;
    else if(!ft_strcmp(av[i], "-u"))
      param_arr[2] = 1;
    else if(!ft_strcmp(av[i], "-t"))
      param_arr[3] = 1;
  }

  ret = param_error(name, num_layers, sizes, &actf);
  if(ret == 2)
  {
    create_conf(name, num_layers, sizes, actf);
    free(sizes);
  }
  else if(ret == 1)
    return NULL;

  free(actf);
  return name;
}

int param_error(char *name, int num_layers, int *sizes, char **actf)
{
  int err_w = 0;
  int conf = 0;

  *actf = !(*actf) ? ft_strdup("logistic") : *actf;

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
