#include "SGD.h"
#include "learning.h"
#include "config.h"

void SGD(neural_net *net, data_set *training_data, int epochs, int mini_batch_size, double l_rate, data_set *test_data)
{
  data_set **mini_batches;
  int n_test;
  int n;

  n_test = test_data ? test_data->set_size : 0;
  n = training_data->set_size;

  for(int i = 0; i < epochs; i++)
  {
    random_shuffle(training_data, i);
    mini_batches = get_batches(training_data, mini_batch_size);
    for(int j = 0; j < (n/mini_batch_size); j++)
      update_mini_batch(net, mini_batches[j], l_rate);
    if(test_data)
      printf("Epoch %d: %d / %d\n", i+1, evaluate(net, test_data), n_test);
    else
      printf("Epoch %d complete\n", i+1);
    free_batches(mini_batches, n/mini_batch_size);
  }

  save_net(net);
}

void random_shuffle(data_set *training_data, int i)
{
  int randy;
  double *peter;
  int size = training_data->set_size;
  if(!i)
    srand(time(NULL));

  for(int j = 0; j < size; j++)
  {
    randy = rand() % size;
    peter = training_data->data[randy];
    training_data->data[randy] = training_data->data[j];
    training_data->data[j] = peter;
    peter = training_data->expout[randy];
    training_data->expout[randy] = training_data->expout[j];
    training_data->expout[j] = peter;
  }
}

data_set **get_batches(data_set *t_data, int mbs)
{
  data_set **mini_batches;

  mini_batches = (data_set **)malloc((t_data->set_size/mbs) * sizeof(data_set *));
  for(int i = 0; i < t_data->set_size/mbs; i++)
  {
    mini_batches[i] = (data_set *)malloc(sizeof(data_set));
    mini_batches[i]->set_size = mbs;
    mini_batches[i]->I_size = t_data->I_size;
    mini_batches[i]->O_size = t_data->O_size;
    mini_batches[i]->data = (double **)malloc(sizeof(double *) * mbs);
    for(int j = 0; j < mini_batches[i]->set_size; j++)
    {
      mini_batches[i]->data[j] = (double *)malloc(sizeof(double) * t_data->I_size);
      for(int k = 0; k < t_data->I_size; k++)
        mini_batches[i]->data[j][k] = t_data->data[(i*mbs)+j][k];
    }
    mini_batches[i]->expout = (double **)malloc(sizeof(double *) * mbs);
    for(int j = 0; j < mini_batches[i]->set_size; j++)
    {
      mini_batches[i]->expout[j] = (double *)malloc(sizeof(double) * t_data->O_size);
      for(int k = 0; k < t_data->O_size; k++)
        mini_batches[i]->expout[j][k] = t_data->expout[(i*mbs)+j][k];
    }
  }

  return mini_batches;
}

void free_batches(data_set **mini_batches, int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < mini_batches[i]->set_size; j++)
    {
      free(mini_batches[i]->expout[j]);
      free(mini_batches[i]->data[j]);
    }
    free(mini_batches[i]->expout);
    free(mini_batches[i]->data);
    free(mini_batches[i]);
  }
  free(mini_batches);
}

void update_mini_batch(neural_net *net, data_set *batch, double l_rate)
{
  double ***delta_w = (double ***)alloc_delta(net, 'w');
  double **delta_b = (double **)alloc_delta(net, 'b');
  double ***n_w = (double ***)alloc_delta(net, 'w');
  double **n_b = (double **)alloc_delta(net, 'b');

  for(int i = 0; i < batch->set_size; i++)
  {
    reset_neural_values(net);
    load_input(net, batch->data[i]);
    feed_forward(net, net->actf);
    backprop_SGD(net, batch->expout[i], delta_b, delta_w);
    for(int j = 0; j < net->num_layers-1; j++)
    {
      for(int m = 0; m < net->sizes[j+1]; m++)
        n_b[j][m] += delta_b[j][m];
      for(int k = 0; k < net->sizes[j]; k++)
        for(int l = 0; l < net->sizes[j+1]; l++)
          n_w[j][k][l] += delta_w[j][k][l];
    }
  }

  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i+1]; j++)
      net->biases[i][j] -= l_rate * (n_b[i][j]/batch->set_size);
  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        net->weights[i][j][k] -= l_rate * (n_w[i][j][k]/batch->set_size);

  free_delta(net, n_b, n_w);
  free_delta(net, delta_b, delta_w);
}
