#include "neural_struct.h"
//#include "config.h" /*REMOVE config.h from neural_struct.h and add neural_struct to config*/

neural_net *construct_neural_net(char *name)
{
  neural_net *net = (neural_net *)malloc(sizeof(neural_net));
  char *conf = get_conf_name(name);

  get_conf_data(conf, ACT_F, net);
  net->name = name;
  get_conf_data(conf, NUM_LAYERS, net);
  net->sizes = (int *)malloc(net->num_layers * sizeof(int));
  get_conf_data(conf, SIZES, net);
  net->biases = (double **)malloc((net->num_layers-1) * sizeof(double *));
  for(int i = 0; i < net->num_layers-1; i++)
    net->biases[i] = (double *)malloc(net->sizes[i+1] * sizeof(double));
  get_conf_data(conf, BIASES, net);
  alloc_weights(net);
  get_conf_data(conf, WEIGHTS, net);
  alloc_layers(net);
  free(conf);

  return net;
}

void alloc_layers(neural_net *net)
{
  net->layers = (neuron ***)malloc(net->num_layers * sizeof(neuron **));
  for(int i = 0; i < net->num_layers; i++)
  {
    net->layers[i] = (neuron **)malloc(net->sizes[i] * sizeof(neuron *));
    for(int j = 0; j < net->sizes[i]; j++)
      net->layers[i][j] = (neuron *)malloc(sizeof(neuron));
  }
}

void alloc_weights(neural_net *net)
{
  net->weights = (double ***)malloc((net->num_layers-1) * sizeof(double **));
  for(int i = 0; i < net->num_layers-1; i++)
  {
    net->weights[i] = (double **)malloc(net->sizes[i] * sizeof(double *));
    for(int j = 0; j < net->sizes[i]; j++)
      net->weights[i][j] = (double *)malloc(net->sizes[i+1] * sizeof(double));
  }
}

void get_conf_data(char *conf, int param, neural_net *net)
{
  char buffer[64];
  FILE *fp = fopen(conf, "r");
  for(int i = 0; i < param; i = fgetc(fp) == '\n' ? i+1 : i);
  fscanf(fp, "%s", buffer);

  switch(param)
  {
    case ACT_F: fscanf(fp, "%s", buffer);
      net->actf = get_actf(buffer);
      break;
    case NUM_LAYERS: fscanf(fp, "%d", &(net->num_layers));
      break;
    case SIZES: for(int i = 0; fscanf(fp, "%d", &(net->sizes[i])); i++);
      break;
    case BIASES:
      for(int i = 0; i < net->num_layers-1; i++)
        for(int j = 0; j < net->sizes[i+1]; j++)
          fscanf(fp, "%lf", &(net->biases[i][j]));
      break;
    case WEIGHTS:
      for(int i = 0; i < net->num_layers-1; i++)
      {
        for(int j = 0; j < net->sizes[i]; j++)
          for(int k = 0; k < net->sizes[i+1]; k++)
            fscanf(fp, "%lf", &(net->weights[i][j][k]));
        fgetc(fp);
      }
      break;
  }

  fclose(fp);
}

void create_format_conf(neural_net *net) /*TODO: REMODEL THE FUNCTION, MAKE MORE IF NEED BE, BUT MAKE IT CLEAN*/
{
  config_t conf;
  config_setting_t *root, *setting, *group, *group2, *group3, *array;
  char layer[256];
  layer[0] = '\0';
  ft_strcat(layer, "layer_");
  char neuron[256];
  neuron[0] = '\0';
  ft_strcat(neuron, "neuron_");


  config_init(&conf);
  config_set_float_precision(&conf, 17);
  root = config_root_setting(&conf);
  group = config_setting_add(root, "net_parameters", CONFIG_TYPE_GROUP);
  setting = config_setting_add(group, "name", CONFIG_TYPE_STRING);
  config_setting_set_string(setting, net->name);
  setting = config_setting_add(group, "num_layers", CONFIG_TYPE_INT);
  config_setting_set_int(setting, net->num_layers);
  array = config_setting_add(group, "sizes", CONFIG_TYPE_ARRAY);
  for(int i = 0; i < net->num_layers; i++)
  {
    setting = config_setting_add(array, NULL, CONFIG_TYPE_INT);
    config_setting_set_int(setting, net->sizes[i]);
  }
  setting = config_setting_add(group, "def_actf", CONFIG_TYPE_STRING);
  config_setting_set_string(setting, get_actf_name(net->actf));
  group = config_setting_add(root, "net_values", CONFIG_TYPE_GROUP);
  group2 = config_setting_add(group, "biases", CONFIG_TYPE_GROUP);
  for(int i = 0; i < net->num_layers-1; i++)
  {
    ft_itoa(i, &layer[6], 10);
    ft_putstr(layer);
    ft_putchar('\n');
    array = config_setting_add(group2, layer, CONFIG_TYPE_ARRAY);
    for(int j = 0; j < net->sizes[i+1]; j++)
    {
      setting = config_setting_add(array, NULL, CONFIG_TYPE_FLOAT);
      config_setting_set_float(setting, net->biases[i][j]);
    }
  }
  group2 = config_setting_add(group, "weights", CONFIG_TYPE_GROUP);
  for(int i = 0; i < net->num_layers-1; i++)
  {
    ft_itoa(i, &layer[6], 10);
    group3 = config_setting_add(group2, layer, CONFIG_TYPE_GROUP);
    for(int j = 0; j < net->sizes[i]; j++)
    {
      ft_itoa(j, &neuron[7], 10);
      array = config_setting_add(group3, neuron, CONFIG_TYPE_ARRAY);
      for(int k = 0; k < net->sizes[i+1]; k++)
      {
        setting = config_setting_add(array, NULL, CONFIG_TYPE_FLOAT);
        config_setting_set_float(setting, net->weights[i][j][k]);
      }
    }
  }

  config_write_file(&conf, get_conf_name(net->name));
  config_destroy(&conf);
}
