#include "learning.h"

int expected_output(neuron **O_layer, double *expout, int size)
{
  int max[2];
  max[0] = 0;
  max[1] = 9;
  for(int i = 0; i < size; i++)
    max[0] = O_layer[i]->output > O_layer[max[0]]->output ? i : max[0];
  for(int i = 9; i >= 0; i--)
    max[1] = expout[i] > expout[max[1]] ? i : max[1];

  if(max[0] == max[1])
    return 1;
  else
    return 0;
}

void backprop(neural_net *net, data_set *batch, double **delta_n_b, double ***delta_n_w, int set_pos) /*TODO: KIND OF FINISHED, BUT UNTESTED*/
{
  int olay = net->num_layers-1;
  for(int i = 0; i < net->sizes[olay]; i++)
  {
    delta_n_b[olay-1][i] = (net->layers[olay][i]->output - batch->expout[set_pos][i]) * (*get_prime(net->actf))(net->layers[olay][i]->input);
    //printf("BACKPROP TEST:\ndelta_n_b[olay-1][i] = %lf\n", delta_n_b[olay-1][i]);
    for(int j = 0; j < net->sizes[olay-1]; j++)
      delta_n_w[olay-1][j][i] = delta_n_b[olay-1][i] * net->layers[olay-1][j]->output;
  }

  for(int l = 1; l < net->num_layers-1; l++)
  {
    for(int i = 0; i < net->sizes[olay-l]; i++)
    {
      delta_n_b[olay-1-l][i] = delta_n_b[olay-l][i] * (*get_prime(net->actf))(net->layers[olay-l][i]->input);
      for(int j = 0; j < net->sizes[olay-l+1]; j++)
        delta_n_b[olay-1-l][i] *= net->weights[olay-l][i][j];
      /*printf("BACKPROP TEST2:\ndelta_n_b[olay-1-l][i] = %lf\n", delta_n_b[olay-1-l][i]);
      printf("delta_n_b[olay-l][i] = %lf\n", delta_n_b[olay-l][i]);
      printf("(*get_prime(net->actf))(net->layers[olay-l][i]->input) = %lf\n", (*get_prime(net->actf))(net->layers[olay-l][i]->input));
      for(int j = 0; j < net->sizes[olay-l+1]; j++)
        printf("net->weights[%d][%d][%d] = %lf\n", olay-l, i, j, net->weights[olay-l][i][j]);*/
      for(int j = 0; j < net->sizes[olay-l-1]; j++)
        delta_n_w[olay-1-l][j][i] = delta_n_b[olay-1-l][i] * net->layers[olay-l-1][j]->output;
    }
  }
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
