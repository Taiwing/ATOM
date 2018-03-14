#include "test.h"

void test_network(neural_net *net)
{
  data_set *training_data;
  data_set *test_data;

  get_data(net->name, &training_data, &test_data, 0, 1000);
  printf("\nresults: %d / %d\n", evaluate(net, test_data), test_data->set_size);
}
