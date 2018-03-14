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
  print_network(net);
  train_network(net, 'g', 3.0);

  return 0;
}
