#include "learning.h"

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
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        delta_w[i][j][k] = net->layers[i][j]->output * delta_b[i][k];

  /*computation of the new weights and biases*/
  for(int i = 0; i < olay; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        net->weights[i][j][k] -= l_rate * delta_w[i][j][k];
    for(int j = 0; j < net->sizes[i+1]; j++)
      net->biases[i][j] -= l_rate * delta_b[i][j];
  }

  free_delta(net, delta_b, delta_w);
}

void backprop_SGD(neural_net *net, double *expout, double **delta_b, double ***delta_w)
{
  int olay = net->num_layers-1; /*index of the output layer*/
  reset_delta(net, delta_b, delta_w); /*resets every value to 0*/

  /*partial derivatives of the biases on the first layer*/
  for(int i = 0; i < net->sizes[olay]; i++) /*deals with output layer*/
  {
    delta_b[olay-1][i] = (net->layers[olay][i]->output - expout[i]) * (*get_prime(net->actf))(net->layers[olay][i]->input);
    /*TEST*/
    //printf("delta_b[%d][%d] = (net->layers[%d][%d]->output - expout[%d]) * (*get_prime(net->actf))(net->layers[%d][%d]->input) = (%.17g - %.17g) * %.17g = %.17g\n", olay-1, i, olay, i, i, olay, i, net->layers[olay][i]->output, expout[i], (*get_prime(net->actf))(net->layers[olay][i]->input), delta_b[olay-1][i]);
  }

  /*partial derivatives of the biases on every hidden layer*/
  for(int i = olay-1; i > 0; i--) /*from the last hidden layer to the first hidden layer*/
  {
    for(int j = 0; j < net->sizes[i]; j++) /*from the first to the last neuron of the layer*/
    {
      for(int k = 0; k < net->sizes[i+1]; k++)
      {
        delta_b[i-1][j] += delta_b[i][k] * net->weights[i][j][k];
        /*TEST*/
        //printf("delta_b[%d][%d] += delta_b[%d][%d] * net->weights[%d][%d][%d] += %.17g * %.17g = %.17g\n", i-1, j, i, k, i, j, k, delta_b[i][k], net->weights[i][j][k], delta_b[i-1][j]);
      }
      delta_b[i-1][j] *= (*get_prime(net->actf))(net->layers[i][j]->input);
      /*TEST*/
      //printf("delta_b[%d][%d] *= (*get_prime(net->actf))(net->layers[%d][%d]->input) *= (*get_prime(net->actf))(%.17g) *= %.17g = %.17g\n", i-1, j, i, j, net->layers[i][j]->input, (*get_prime(net->actf))(net->layers[i][j]->input), delta_b[i-1][j]);
    }
  }

  /*partial derivatives of the weights on every layer*/
  for(int i = 0; i < olay; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
      {
        delta_w[i][j][k] = net->layers[i][j]->output * delta_b[i][k];
        /*TEST*/
        //printf("delta_w[%d][%d][%d] = net->layers[%d][%d]->output * delta_b[%d][%d] = %.17g * %.17g = %.17g\n", i, j, k, i, j, i, k, net->layers[i][j]->output, delta_b[i][k], delta_w[i][j][k]);
      }
  }

  /*TEST*/
  /*if(!ft_strcmp(net->name, "handy_s"))
  {
    printf("OUT:");
    for(int j = 0; j < net->sizes[olay]; j++)
      printf(" %.17g", net->layers[olay][j]->output);
    int max = 0;
    int i = 0;
    for(; i < net->sizes[olay]; i++)
      max = net->layers[olay][i]->output > net->layers[olay][max]->output ? i : max;
    printf("\noutput = %d\n", max);
    i = 0;
    for(; i < net->sizes[olay]; i++)
      max = expout[i] > expout[max] ? i : max;
    printf("expout = %d\n\n", max);
  }
  else if(!ft_strcmp(net->name, "16N3C_s"))
  {
    char ans[4];
    int val;
    printf("OUT:");
    for(int j = 0; j < net->sizes[olay]; j++)
      printf(" %.17g", net->layers[olay][j]->output);
    for(int i = 0; i < 4; i++)
    {
      if(i < 3)
        val = net->layers[olay][i]->output < 0.5 ? 0 : 1;
      ans[i] = i == 3 ? '\0' : val+48;
    }
    printf("\noutput = %s\n", ans);
    for(int i = 0; i < 4; i++)
    {
      if(i < 3)
        val = expout[i] < 0.5 ? 0 : 1;
      ans[i] = i == 3 ? '\0' : val+48;
    }
    printf("expout = %s\n\n", ans);
  }*/

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

void free_delta(neural_net *net, double **delta_b, double ***delta_w)
{
  for(int i = 0; i < net->num_layers-1; i++)
    free(delta_b[i]);
  free(delta_b);

  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
      free(delta_w[i][j]);
    free(delta_w[i]);
  }
  free(delta_w);
}

void reset_delta(neural_net *net, double **delta_b, double ***delta_w)
{
  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i+1]; j++)
      delta_b[i][j] = 0;
  for(int i = 0; i < net->num_layers-1; i++)
    for(int j = 0; j < net->sizes[i]; j++)
      for(int k = 0; k < net->sizes[i+1]; k++)
        delta_w[i][j][k] = 0;
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
      fprintf(fp, " %.17g", net->biases[i][j]);
  fprintf(fp, "\nWEIGHTS\n");
  for(int i = 0; i < net->num_layers-1; i++)
  {
    for(int j = 0; j < net->sizes[i]; j++)
    {
      for(int k = 0; k < net->sizes[i+1]; k++)
      {
        fprintf(fp, "%.17g", net->weights[i][j][k]);
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
