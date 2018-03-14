#include "neural_struct.h"

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
