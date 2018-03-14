#include "neural_struct.h"
#include "config.h"

neural_net *construct_neural_net(char *name)
{
  neural_net *net = (neural_net *)malloc(sizeof(neural_net));
  char *conf = get_conf_name(name);

  load_conf_data(conf, net);
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
    {
      net->layers[i][j] = (neuron *)malloc(sizeof(neuron));
      net->layers[i][j]->actf = NULL;
    }
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

void free_net(neural_net *net)
{
  for(int i = 0; i < net->num_layers-1; i++)
    free(net->biases[i]);
  free(net->biases);
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
      free(net->weights[i][j]);
    free(net->weights[i]);
  }
  free(net->weights);
  for(int i = 0; i < net->num_layers; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
      free(net->layers[i][j]);
    free(net->layers[i]);
  }
  free(net->layers);
  free(net->sizes);
  free(net);
}
