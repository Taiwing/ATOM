#include "training.h"

void train_network(neural_net *net, char method, double l_rate)
{
  data_set *training_data;
  data_set *test_data;

  get_data(net->name, &training_data, &test_data, 10000, 1000);

  /*TEMPORARY: _s suffix is gonna set stochastic gradient descent*/
  int i = 0;
  for(; net->name[i]; i++);
  method = net->name[i-1] == 's' ? 's' : 'g';

  switch(method)
  {
    case 'g':
      GD(net, training_data, test_data, l_rate);
      break;
    case 's':
      SGD(net, training_data, 30, 10, l_rate, test_data);
      break;
  }
}
