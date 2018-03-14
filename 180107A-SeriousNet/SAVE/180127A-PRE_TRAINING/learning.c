#include "learning.h"

void backprop(neural_net *net, data_set *batch, double **delta_b, double ***delta_w, int set_pos) /*TODO: KIND OF FINISHED, BUT UNTESTED*/
{
  int olay = net->num_layers-1;
  for(int i = 0; i < net->sizes[olay]; i++)
  {
    delta_b[olay-1][i] = (net->layers[olay][i]->output - batch->expout[set_pos][i]) * (*get_prime(net->actf))(net->layers[olay][i]->input);
    //printf("\nBACKPROP TEST:\ndelta_b[olay-1][i] = %lf\n", delta_b[olay-1][i]);
    for(int j = 0; j < net->sizes[olay-1]; j++)
      delta_w[olay-1][j][i] = delta_b[olay-1][i] * net->layers[olay-1][j]->output;
  }

  for(int l = 1; l < net->num_layers-1; l++)
  {
    for(int i = 0; i < net->sizes[olay-l]; i++)
    {
      delta_b[olay-1-l][i] = delta_b[olay-l][i] * (*get_prime(net->actf))(net->layers[olay-l][i]->input);
      for(int j = 0; j < net->sizes[olay-l+1]; j++)
        delta_b[olay-1-l][i] *= net->weights[olay-l][i][j];
      /*printf("\nBACKPROP TEST2:\ndelta_b[olay-1-l][i] = %lf\n", delta_b[olay-1-l][i]);
      printf("delta_b[olay-l][i] = %lf\n", delta_b[olay-l][i]);
      printf("(*get_prime(net->actf))(net->layers[olay-l][i]->input) = %lf\n", (*get_prime(net->actf))(net->layers[olay-l][i]->input));
      for(int j = 0; j < net->sizes[olay-l+1]; j++)
        printf("net->weights[%d][%d][%d] = %lf\n", olay-l, i, j, net->weights[olay-l][i][j]);
      for(int j = 0; j < net->sizes[olay-l-1]; j++)
        delta_w[olay-1-l][j][i] = delta_b[olay-1-l][i] * net->layers[olay-l-1][j]->output;*/
    }
  }
}

void back_propagation(neural_net *net, double *expout, double l_rate)
{
  int olay = net->num_layers-1; /*index of the output layer*/
  double ***delta_w = (double ***)alloc_delta(net, 'w');
  double **delta_b = (double **)alloc_delta(net, 'b');

  /*partial derivatives of the biases on the first layer*/
  for(int i = 0; i < net->sizes[olay]; i++) /*deals with output layer*/
    delta_b[olay-1][i] = (net->layers[olay][i]->output - expout[i]) * (*get_prime(net->actf))(net->layers[olay][i]->input);

  /*partial derivatives of the biases on every hidden layer*/
  for(int i = olay-1; i > 0; i--) /*from the last hidden layer to the first hidden layer*/
  {
    for(int j = 0; j < net->sizes[i]; j++) /*from the first to the last neuron of the layer*/
    {
      for(int k = 0; k < net->sizes[i+1]; k++)
        delta_b[i-1][j] += delta_b[i][k] * net->weights[i][j][k];
      delta_b[i-1][j] *= (*get_prime(net->actf))(net->layers[i][j]->input);
    }
  }

  /*partial derivatives of the weights on every layer*/
  for(int i = 0; i < olay; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        delta_w[i][j][k] = net->layers[i][j]->output * delta_b[i][k];
  }

  /*computation of the new weights and biases*/
  for(int i = 0; i < olay; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        net->weights[i][j][k] -= l_rate * delta_w[i][j][k];
    for(int j = 0; j < net->sizes[i+1]; j++)
      net->biases[i][j] -= l_rate * delta_b[i][j];
  }

  free(delta_b);
  free(delta_w);
}

void *alloc_delta(neural_net *net, char c)
{
  if(c == 'w')
  {
    double ***delta_w = (double ***)malloc((net->num_layers-1) * sizeof(double **));
    for(int i = 0; i < net->num_layers-1; i++)
    {
      delta_w[i] = (double **)malloc(net->sizes[i] * sizeof(double *));
      for(int j = 0; j < net->sizes[i]; j++)
      {
        delta_w[i][j] = (double *)malloc(net->sizes[i+1] * sizeof(double));
        for(int k = 0; k < net->sizes[i+1]; k++)
          delta_w[i][j][k] = 0;
      }
    }
    return delta_w;
  }
  else if(c == 'b')
  {
    double **delta_b = (double **)malloc((net->num_layers-1) * sizeof(double *));
    for(int i = 0; i < net->num_layers-1; i++)
    {
      delta_b[i] = (double *)malloc(net->sizes[i+1] * sizeof(double));
      for(int j = 0; j < net->sizes[i+1]; j++)
        delta_b[i][j] = 0;
    }
    return delta_b;
  }
  else
    return NULL;
}

void save_weights(neural_net *net)
{
  char *conf = get_conf_name(net->name);
  FILE *fp = fopen(conf, "w+");

  fprintf(fp, "ACT_F %s\n", get_actf_name(net->actf));
  fprintf(fp, "NUM_LAYERS %d\nSIZES", net->num_layers);
  for(int i = 0; i < net->num_layers; i++)
    fprintf(fp, " %d", net->sizes[i]);
  fprintf(fp, "\nBIASES");
  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i+1]; j++)
      fprintf(fp, " %lf", net->biases[i][j]);
  fprintf(fp, "\nWEIGHTS\n");
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
    {
      for(int k = 0; k < net->sizes[i+1]; k++)
      {
        fprintf(fp, "%lf", net->weights[i][j][k]);
        if(k < net->sizes[i+1]-1)
          fprintf(fp, " ");
      }
      fprintf(fp, "\n");
    }
    if(i != net->num_layers-2)
      fprintf(fp, "\n");
  }

  free(conf);
  fclose(fp);
}
