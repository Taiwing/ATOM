#include "GD.h"

void GD(neural_net *net, data_set *training_data, data_set *test_data, double l_rate)
{
  for(int i = 0; i < training_data->set_size; i++)
  {
    reset_neural_values(net);
    load_input(net, training_data->data[i]);
    feed_forward(net, net->actf);
    back_propagation(net, training_data->expout[i], l_rate);
  }
  printf("\nresults: %d / %d\n", evaluate(net, test_data), test_data->set_size);
  save_weights(net);
}
