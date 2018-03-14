#include "main.h"

int main(int argc, char *argv[])
{
  int num_layers = argc;
  int *sizes = NULL;
  char *name = NULL;

  if(!get_params(&name, &num_layers, sizes, argv))
  {
    printf("Error: wrong arguments\n");
    exit(EXIT_FAILURE);
  }

  neural_net *net;
  net = construct_neural_net(name);

  printf("Network %s:\n", net->name);
  printf("num_layers: %d\n", net->num_layers);
  printf("sizes: ");
  for(int i = 0; i < net->num_layers; i++)
    printf("%d ", net->sizes[i]);
  printf("\nbiases: ");
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i+1]; j++)
      printf("%lf ", net->biases[i][j]);
  }
  printf("\nweights:\n");
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
    {
      for(int k = 0; k < net->sizes[i+1]; k++)
        printf("%lf ", net->weights[i][j][k]);
      printf("\n");
    }
    printf("\n");
  }

  double val = 2.3;
  double *input = (double *)malloc(net->sizes[0] * sizeof(double));
  for(int i = 0; i < net->sizes[0]; i++)
    input[i] = val * i;
  reset_neural_values(net);
  load_input(net, input);
  feed_forward(net, &logistic);
  printf("\nresults:\n");
  for(int i = 0; i < net->sizes[net->num_layers-1]; i++)
    printf("%lf\n", net->layers[net->num_layers-1][i]->output);

  return 0;
}
