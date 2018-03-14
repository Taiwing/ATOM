#include "main.h"

int main(int argc, char *argv[])
{
  int param_arr[4] = {0};

  char *name = get_params(argc, argv, param_arr);

  if(!name)
  {
    printf("Error: wrong arguments\n");
    exit(EXIT_FAILURE);
  }

  neural_net *net = construct_neural_net(name);

  if(param_arr[0])
    print_network(net);
  if(param_arr[1])
    test_network(net);
  if(param_arr[2])
    printf("use_network\n"); //use_network(net, set);
  if(param_arr[3])
    train_network(net, 'g', 3.0);

  return 0;
}
