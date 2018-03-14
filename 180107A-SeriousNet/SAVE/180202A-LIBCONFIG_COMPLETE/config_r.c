#include "config.h"

void load_conf_data(char *conf, neural_net *net) /*TODO: TO SIMPLIFY*/
{
  const char *buffer = NULL;
  config_t config;
  config_setting_t *root, *group, *layer, *array;
  config_init(&config);
  config_read_file(&config, conf);
  root = config_root_setting(&config);
  group = config_setting_get_member(root, "net_parameters");

  config_lookup_string(&config, "net_parameters.name", &buffer);
  net->name = strdup(buffer);

  config_lookup_int(&config, "net_parameters.num_layers", &(net->num_layers));
  config_lookup_string(&config, "net_parameters.def_actf", &buffer);
  net->actf = get_actf((char *)buffer);
  net->sizes = (int *)malloc(net->num_layers * sizeof(int));
  array = config_setting_get_member(group, "sizes");
  for(int i = 0; i < net->num_layers; i++)
    net->sizes[i] = config_setting_get_int_elem(array, i);


  group = config_setting_get_member(config_setting_get_member(root, "net_values"), "biases");
  net->biases = (double **)malloc((net->num_layers-1) * sizeof(double *));
  for(int i = 0; i < net->num_layers-1; i++)
  {
    net->biases[i] = (double *)malloc(net->sizes[i+1] * sizeof(double));
    array = config_setting_get_elem(group, i);
    for(int j = 0; j < net->sizes[i+1]; j++)
      net->biases[i][j] = config_setting_get_float_elem(array, j);
  }
  alloc_weights(net);
  group = config_setting_get_member(config_setting_get_member(root, "net_values"), "weights");
  for(int i = 0; i < net->num_layers-1; i++)
  {
    layer = config_setting_get_elem(group, i);
    for(int j = 0; j < net->sizes[i]; j++)
    {
      array = config_setting_get_elem(layer, j);
      for(int k = 0; k < net->sizes[i+1]; k++)
        net->weights[i][j][k] = config_setting_get_float_elem(array, k);
    }
  }

  config_destroy(&config);
}
