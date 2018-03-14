#include "SGD.h"
#include "learning.h"

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
      printf("Epoch %d: %d / %d\n", i, evaluate(net, test_data), n_test);
    else
      printf("Epoch %d complete\n", i);
    free(mini_batches);
  }

  save_weights(net);
}

void random_shuffle(data_set *training_data, int i)
{
  int randy;
  double *peter;
  int size = training_data->set_size;
  if(!i && training_data->set_size != 600) /*exception for TEST network*/
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

void update_mini_batch(neural_net *net, data_set *batch, double l_rate)
{
  /*INITIALISATIONS OF ARRAYS: FIND A WAY TO HIDE IT OR MAKE IT SHORTER*/
  double **n_b = (double **)malloc((net->num_layers-1) * sizeof(double *));
  for(int i = 0; i < net->num_layers-1; i++)
  {
    n_b[i] = (double *)malloc(net->sizes[i+1] * sizeof(double));
    for(int j = 0; j < net->sizes[i+1]; j++)
      n_b[i][j] = 0;
  }
  double ***n_w = (double ***)malloc((net->num_layers-1) * sizeof(double **));
  for(int i = 0; i < net->num_layers-1; i++)
  {
    n_w[i] = (double **)malloc(net->sizes[i] * sizeof(double *));
    for(int j = 0; j < net->sizes[i]; j++)
    {
      n_w[i][j] = (double *)malloc(net->sizes[i+1] * sizeof(double));
      for(int k = 0; k < net->sizes[i+1]; k++)
        n_w[i][j][k] = 0;
    }
  }
  double **delta_n_b = (double **)malloc((net->num_layers-1) * sizeof(double *));
  for(int i = 0; i < net->num_layers-1; i++)
  {
    delta_n_b[i] = (double *)malloc(net->sizes[i+1] * sizeof(double));
    for(int j = 0; j < net->sizes[i+1]; j++)
      delta_n_b[i][j] = 0;
  }
  double ***delta_n_w = (double ***)malloc((net->num_layers-1) * sizeof(double **));
  for(int i = 0; i < net->num_layers-1; i++)
  {
    delta_n_w[i] = (double **)malloc(net->sizes[i] * sizeof(double *));
    for(int j = 0; j < net->sizes[i]; j++)
    {
      delta_n_w[i][j] = (double *)malloc(net->sizes[i+1] * sizeof(double));
      for(int k = 0; k < net->sizes[i+1]; k++)
        delta_n_w[i][j][k] = 0;
    }
  }
  /*INITIALISATIONS OF ARRAYS: FIND A WAY TO HIDE IT OR MAKE IT SHORTER*/

  for(int i = 0; i < batch->set_size; i++)
  {
    reset_neural_values(net);
    load_input(net, batch->data[i]);
    feed_forward(net, net->actf);
    backprop(net, batch, delta_n_b, delta_n_w, i);
    for(int j = 0; j < net->num_layers-1; j++)
    {
      for(int m = 0; m < net->sizes[j+1]; m++)
        n_b[j][m] += delta_n_b[j][m];
      for(int k = 0; k < net->sizes[j]; k++)
        for(int l = 0; l < net->sizes[j+1]; j++)
          n_w[j][k][l] += delta_n_w[j][k][l];
    }
  }

  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i+1]; j++)
      net->biases[i][j] = (net->biases[i][j] - (l_rate/batch->set_size)) * n_b[i][j];
  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        net->weights[i][j][k] = (net->weights[i][j][k] - (l_rate/batch->set_size)) * n_w[i][j][k];

  //printf("TEST:\nnet->weights[0][2][3] = %lf\nn_w[0][2][3] = %lf\ndelta_n_w[0][2][3] = %lf\n", net->weights[0][2][3], n_w[0][2][3], delta_n_w[0][2][3]);

  free(n_b);
  free(n_w);
  free(delta_n_b);
  free(delta_n_w);

  /*for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i+1]; j++)
      net->biases[i][j] = ((net->biases[i][j]-(l_rate/batch->set_size)) * n_b[i][j]);
  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        net->weights[i][j][k] = ((net->weights[i][j][k]-(l_rate/batch->set_size)) * n_w[i][j][k]);*/
}
