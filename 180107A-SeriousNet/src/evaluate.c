#include "evaluate.h"

int evaluate(neural_net *net, data_set *test_data)
{
  int test_results = 0;

  for(int i = 0; i < test_data->set_size; i++)
  {
    reset_neural_values(net);
    load_input(net, test_data->data[i]);
    feed_forward(net);
    if(!ft_strcmp(net->name, "16N3") || !ft_strcmp(net->name, "16N3_s") || !ft_strcmp(net->name, "16N3C") || !ft_strcmp(net->name, "16N3C_s"))
      test_results = expected_output_16N3(net->layers[net->num_layers-1], test_data->expout[i], test_data->O_size) ? test_results + 1 : test_results;
    else if(expected_output(net->layers[net->num_layers-1], test_data->expout[i], test_data->O_size))
      test_results++;
  }

  return test_results;
}

int expected_output(neuron **O_layer, double *expout, int size)
{
  int max[2];
  max[0] = 0;
  max[1] = 0;
  for(int i = 0; i < size; i++)
  {
    max[0] = O_layer[i]->output > O_layer[max[0]]->output ? i : max[0];
    max[1] = expout[i] > expout[max[1]] ? i : max[1];
  }

  if(max[0] == max[1])
    return 1;
  else
    return 0;
}

int expected_output_16N3(neuron **O_layer, double *expout, int size)
{
  int test = 0;
  for(int i = 0; i < size; i++)
  {
    if((O_layer[i]->output >= 0.95 && expout[i] >= 0.95) || (O_layer[i]->output <= 0.05 && expout[i] <= 0.05))
      test++;
  }
  if(test == 3)
    return 1;
  else
    return 0;
}
