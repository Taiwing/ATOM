#include "print.h"

void print_network(neural_net *net)
{
  printf("Network %s:\n", net->name);
  printf("def_actf: %s\n", get_actf_name(net->def_actf));
  printf("num_layers: %d\n", net->num_layers);
  printf("sizes: ");
  for(int i = 0; i < net->num_layers; i++)
    printf("%d ", net->sizes[i]);
  printf("\nbiases: ");
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i+1]; j++)
      printf("%.17g ", net->biases[i][j]);
  }
  printf("\nweights:\n");
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
    {
      for(int k = 0; k < net->sizes[i+1]; k++)
        printf("%.17g ", net->weights[i][j][k]);
      printf("\n");
    }
    printf("\n");
  }
}
