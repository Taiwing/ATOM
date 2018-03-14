#include "use.h"

void use_network(neural_net *net, data_set *set)
{
  for(int i = 0; i < set->set_size; i++)
  {
    if(set->set_size > 1)
      printf("FEED %d:\n", i);
    reset_neural_values(net);
    load_input(net, set->data[i]);
    feed_forward_print(net);
  }
}
