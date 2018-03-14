#include "config.h"

void create_conf(char *name, int num_layers, int *sizes, char *actf)
{
  srand(time(NULL));
  neural_net *net = (neural_net *)malloc(sizeof(neural_net));
  net->name = name;
  net->num_layers = num_layers;
  net->def_actf = get_actf(actf);
  net->sizes = (int *)malloc(num_layers * sizeof(int));
  for(int i = 0; i < num_layers; i++)
    net->sizes[i] = sizes[i];
  net->biases = (double **)malloc((num_layers-1) * sizeof(double *));
  for(int i = 0; i < num_layers-1; i++)
  {
    net->biases[i] = (double *)malloc(sizes[i+1] * sizeof(double));
    for(int j = 0; j < sizes[i+1]; j++)
      net->biases[i][j] = rand_double(0.1, 0.99);
  }
  alloc_weights(net);
  for(int i = 0; i < num_layers-1; i++)
    for(int j = 0; j < sizes[i]; j++)
      for(int k = 0; k < sizes[i+1]; k++)
        net->weights[i][j][k] = rand_double(0.1, 0.99);
  alloc_layers(net);
  save_net(net);
  free_net(net);
}

void save_net(neural_net *net)
{
  config_t conf;
  config_init(&conf);
  config_set_float_precision(&conf, 17);

  write_net_parameters(net, &conf);
  write_neuron_actf(net, &conf);
  write_net_biases(net, &conf);
  write_net_weights(net, &conf);

  config_write_file(&conf, get_conf_name(net->name));
  config_destroy(&conf);
}

void write_net_parameters(neural_net *net, config_t *conf)
{
  config_setting_t *root, *setting, *group, *array;

  root = config_root_setting(conf);
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
  config_setting_set_string(setting, get_actf_name(net->def_actf));
}

void write_neuron_actf(neural_net *net, config_t *conf) /*UNTESTED*/
{
  int c[ACTF_N];
  int def_i = actf_i(net->def_actf);
  int def_lay_i;
  int not_def;
  config_setting_t *neuron_actf = NULL, *layer_X, *setting;
  char layer_s[256], neuron_s[256];
  layer_s[0] = '\0';
  neuron_s[0] = '\0';
  ft_strcat(layer_s, "layer_");
  ft_strcat(neuron_s, "neuron_");

  for(int i = 1; i < net->num_layers; i++)
  {
    for(int j = 0; j < ACTF_N; j++) /*resets the counter*/
      c[j] = 0;
    for(int j = 0; j < net->sizes[i]; j++) /*counts the different act_f of the layer*/
      c[actf_i(net->layers[i][j]->actf)]++;
    not_def = 0;
    for(int j = 0; j < ACTF_N; j++) /*verifies if at least one neuron is different from def_actf*/
      not_def = (j != def_i && c[j] > 0) ? 1 : not_def;
    if(not_def) /*is it is the case*/
    {
      /*write neuron_actf if it doesn't exist and layer_X*/
      neuron_actf = (!neuron_actf) ? config_setting_add(config_root_setting(conf), "neuron_actf", CONFIG_TYPE_GROUP) : neuron_actf;
      ft_itoa(i, &layer_s[6], 10);
      layer_X = config_setting_add(neuron_actf, layer_s, CONFIG_TYPE_GROUP);
      def_lay_i = def_i;
      for(int j = 0; j < ACTF_N; j++) /*gets the biggest actf function on the layer*/
        def_lay_i = (j != def_lay_i && c[j] > c[def_lay_i]) ? j : def_lay_i;
      for(int j = 0; j < net->sizes[i]; j++) /*writes every neuron_X exception*/
      {
        if(actf_i(net->layers[i][j]->actf) != def_lay_i)
        {
          ft_itoa(j, &neuron_s[7], 10);
          setting = config_setting_add(layer_X, neuron_s, CONFIG_TYPE_STRING);
          config_setting_set_string(setting, get_actf_name(net->layers[i][j]->actf));
        }
      }
      if(def_lay_i != def_i) /*if the default actf of the layer is different from def_actf*/
      {
        setting = config_setting_add(layer_X, "layer", CONFIG_TYPE_STRING);
        config_setting_set_string(setting, i_actf(def_lay_i));
      }
    }
  }
}

void write_net_biases(neural_net *net, config_t *conf)
{
  config_setting_t *setting, *group, *group2, *array;
  char layer[256];
  layer[0] = '\0';
  ft_strcat(layer, "layer_");

  group = config_setting_add(config_root_setting(conf), "net_values", CONFIG_TYPE_GROUP);
  group2 = config_setting_add(group, "biases", CONFIG_TYPE_GROUP);
  for(int i = 0; i < net->num_layers-1; i++)
  {
    ft_itoa(i, &layer[6], 10);
    array = config_setting_add(group2, layer, CONFIG_TYPE_ARRAY);
    for(int j = 0; j < net->sizes[i+1]; j++)
    {
      setting = config_setting_add(array, NULL, CONFIG_TYPE_FLOAT);
      config_setting_set_float(setting, net->biases[i][j]);
    }
  }
}

void write_net_weights(neural_net *net, config_t *conf)
{
  config_setting_t *setting, *group, *group2, *group3, *array;
  char layer[256], neuron[256];
  layer[0] = '\0';
  neuron[0] = '\0';
  ft_strcat(layer, "layer_");
  ft_strcat(neuron, "neuron_");

  group = config_setting_get_member(config_root_setting(conf), "net_values");
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
}
