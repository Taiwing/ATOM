#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H
#include "neural_struct.h"
#include "activation_functions.h"

typedef struct data_set
{
  double **data;    /*input data for the net: data[set_size][net->size[0]]*/
  double **expout;  /*expected output: data[set_size][net->size[num_layers-1]]*/
  int set_size;     /*size of the data_set (of both arrays)*/
  int I_size;       /*width of the input layer*/
  int O_size;       /*width of the output layer*/
} data_set;

void load_input(neural_net *net, double *input);
void feed_forward(neural_net *net);
void feed_forward_print(neural_net *net);
void reset_neural_values(neural_net *net);

#endif
