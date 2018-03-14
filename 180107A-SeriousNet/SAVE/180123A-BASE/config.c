#include "config.h"

void create_conf(char *conf, int num_layers, int *sizes)
{
  FILE *fp = fopen(conf, "w");
  srand(time(NULL));

  fprintf(fp, "NUM_LAYERS %d\nSIZES", num_layers);
  for(int i = 0; i < num_layers; i++)
    fprintf(fp, " %d", sizes[i]);
  fprintf(fp, "\nBIASES");
  for(int i = 0; i < num_layers-1; i++)
    fprintf(fp, " %lf", rand_double(0.5, 4.5));
  fprintf(fp, "\nWEIGHTS\n");
  for(int i = 0; i < num_layers-1; i++)
  {
    for(int j = 0; j < sizes[i]; j++)
    {
      for(int k = 0; k < sizes[i+1]; k++)
      {
        fprintf(fp, "%lf", rand_double(0.1, 0.99));
        if(k < sizes[i+1]-1)
          fprintf(fp, " ");
      }
      fprintf(fp, "\n");
    }
    if(i != num_layers-2)
      fprintf(fp, "\n");
  }

  fclose(fp);
}

double rand_double(double min, double max)
{
  double val = (double)rand();
  return fmod(val, (max-min)) + min;
}

char *get_conf_name(char *name)
{
  int i;
  char *conf;

  i = 0;
  conf = (char *)malloc(ft_strlen(name)+4);

  for(; name[i]; i++)
    conf[i] = name[i];

  conf[i] = '\0';
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
