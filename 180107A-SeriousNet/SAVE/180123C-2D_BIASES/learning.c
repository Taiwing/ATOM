#include "learning.h"

int expected_output(neuron **O_layer, double *expout, int size)
{
  int max[2];
  max[0] = 0;
  max[1] = 0;
  for(int i = 0; i < size; i++)
  {
    max[0] = O_layer[i]->output > O_layer[max[0]]->output ? i : max[0];
    max[1] = expout[i] > expout[max[0]] ? i : max[0];
  }

  if(max[0] == max[1])
    return 1;
  else
    return 0;
}

void backprop(neural_net *net, data_set *batch, double **delta_n_b, double ***delta_n_w, int set_pos)
{
  int olay = net->num_layers-1;
  for(int i = 0; i < net->sizes[olay]; i++)
  {
    delta_n_b[olay-1][i] = (net->layers[olay][i]->output - batch->expout[set_pos][i]) * (*get_prime(&logistic))(net->layers[olay][i]->input);
    for(int j = 0; j < net->sizes[olay-1]; j++)
      delta_n_w[olay-1][j][i] = delta_n_b[olay-1][i] * net->layers[olay-1][j]->output;
  }
}
