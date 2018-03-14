#include "config.h"

void load_conf_data(char *conf, neural_net *net)
{
  config_t config;
  config_setting_t *root;

  config_init(&config);
  config_read_file(&config, conf);
  root = config_root_setting(&config);

  get_net_parameters(net, &config, config_setting_get_member(root, "net_parameters"));
  get_neuron_actf(net, config_setting_get_member(root, "neuron_actf"));
  get_net_values(net, config_setting_get_member(root, "net_values"));

  config_destroy(&config);
}

void get_net_parameters(neural_net *net, config_t *config, config_setting_t *net_parameters)
{
  const char *buffer = NULL;
  config_setting_t *array;

  config_lookup_string(config, "net_parameters.name", &buffer);
  net->name = strdup(buffer);
  config_lookup_int(config, "net_parameters.num_layers", &(net->num_layers));
  config_lookup_string(config, "net_parameters.def_actf", &buffer);
  net->def_actf = get_actf((char *)buffer);
  net->sizes = (int *)malloc(net->num_layers * sizeof(int));
  array = config_setting_get_member(net_parameters, "sizes");
  for(int i = 0; i < net->num_layers; i++)
    net->sizes[i] = config_setting_get_int_elem(array, i);
}

void get_neuron_actf(neural_net *net, config_setting_t *neuron_actf)
{
  config_setting_t *layer_X = NULL;
  config_setting_t *neuron_X = NULL;
  config_setting_t *layer = NULL;
  char layer_s[256], neuron_s[256];
  layer_s[0] = '\0';
  neuron_s[0] = '\0';
  ft_strcat(layer_s, "layer_");
  ft_strcat(neuron_s, "neuron_");

  alloc_layers(net);
  for(int i = 1; i < net->num_layers; i++)
  {
    if(neuron_actf)
    {
      ft_itoa(i, &layer_s[6], 10);
      layer_X = config_setting_get_member(neuron_actf, layer_s);
    }
    for(int j = 0; j < net->sizes[i]; j++)
    {
      if(layer_X)
      {
        ft_itoa(j, &neuron_s[7], 10);
        neuron_X = config_setting_get_member(layer_X, neuron_s);
        layer = config_setting_get_member(layer_X, "layer");
        if(neuron_X)
          net->layers[i][j]->actf = get_actf((char *)config_setting_get_string(neuron_X));
        else if(layer)
          net->layers[i][j]->actf = get_actf((char *)config_setting_get_string(layer));
      }
      net->layers[i][j]->actf = net->layers[i][j]->actf == NULL ? net->def_actf : net->layers[i][j]->actf;
    }
  }
}

void get_net_values(neural_net *net, config_setting_t *net_values)
{
  config_setting_t *group, *array, *layer;

  group = config_setting_get_member(net_values, "biases");
  net->biases = (double **)malloc((net->num_layers-1) * sizeof(double *));
  for(int i = 0; i < net->num_layers-1; i++)
  {
    net->biases[i] = (double *)malloc(net->sizes[i+1] * sizeof(double));
    array = config_setting_get_elem(group, i);
    for(int j = 0; j < net->sizes[i+1]; j++)
      net->biases[i][j] = config_setting_get_float_elem(array, j);
  }

  alloc_weights(net);
  group = config_setting_get_member(net_values, "weights");
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
}
