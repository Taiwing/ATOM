#include "data_processing.h"

void load_input(neural_net *net, double *data)
{
  for(int i = 0; i < net->sizes[0]; i++)
    net->layers[0][i]->output = data[i];
}

void feed_forward(neural_net *net, double (*actf)(double x))
{
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i+1]; j++)
    {
      for(int k = 0; k < net->sizes[i]; k++)
        net->layers[i+1][j]->input += (net->layers[i][k]->output * net->weights[i][k][j]);
      net->layers[i+1][j]->input += net->biases[i][j];
      net->layers[i+1][j]->output = (*actf)(net->layers[i+1][j]->input);
    }
  }
}

void feed_forward_print(neural_net *net, double (*actf)(double x))
{
  for(int i = 0; i < net->sizes[0]; i++)
    printf("input[%d] = %lf\n", i, net->layers[0][i]->output);

  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i+1]; j++)
    {
      for(int k = 0; k < net->sizes[i]; k++)
        net->layers[i+1][j]->input += (net->layers[i][k]->output * net->weights[i][k][j]);
      net->layers[i+1][j]->input += net->biases[i][j];
      net->layers[i+1][j]->output = (*actf)(net->layers[i+1][j]->input);
    }
  }

  for(int i = 0; i < net->sizes[net->num_layers-1]; i++)
    printf("output[%d] = %lf\n", i, net->layers[net->num_layers-1][i]->output);

  printf("\n");
}

void reset_neural_values(neural_net *net)
{
  for(int i = 0; i < net->num_layers; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
    {
      net->layers[i][j]->input = 0;
      net->layers[i][j]->output = 0;
    }
  }
}
