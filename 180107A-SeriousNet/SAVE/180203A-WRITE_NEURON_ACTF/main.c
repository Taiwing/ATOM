#include "main.h"

int main(int argc, char *argv[])
{
  char *name = get_params(argc, argv);

  if(!name)
  {
    printf("Error: wrong arguments\n");
    exit(EXIT_FAILURE);
  }

  neural_net *net = construct_neural_net(name);

  /*if(!ft_strcmp(net->name, "test"))
  {
    for(int i = 0; i < net->sizes[2]; i++)
      net->layers[2][i]->actf = get_actf("ReLU");
    net->layers[2][3]->actf = get_actf("binary_step");
    net->layers[2][5]->actf = get_actf("binary_step");
    net->layers[2][3]->actf = get_actf("soft_sign");
    net->layers[2][8]->actf = get_actf("identity");
    net->layers[2][9]->actf = get_actf("soft_sign");
    net->layers[2][11]->actf = get_actf("binary_step");
    save_net(net);
  }*/

  print_network(net);

  //test_network(net);

  //train_network(net, 'g', 3.0);

  return 0;
}
