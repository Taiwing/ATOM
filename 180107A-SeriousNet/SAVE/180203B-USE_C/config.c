#include "config.h"

double rand_double(double min, double max)
{
  double val = (double)rand();
  return fmod(val, (max-min)) + min;
}

char *get_conf_name(char *name)
{
  char *conf;

  conf = (char *)malloc(ft_strlen(name)+9);

  ft_strcpy(conf, "nets/");
  ft_strcat(conf, name);
  ft_strcat(conf, ".nn");

  return conf;
}

int does_config_exist(char *name)
{
  char *conf = get_conf_name(name);
  FILE *fp = fopen(conf, "r");

  if(fp)
  {
    fclose(fp);
    return 1;
  }
  else
    return 0;
}
