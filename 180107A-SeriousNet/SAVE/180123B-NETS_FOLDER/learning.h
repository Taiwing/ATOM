#ifndef LEARNING_H
#define LEARNING_H
#include "neural_struct.h"
#include "data_processing.h"

int expected_output(neuron **O_layer, double *expout, int size);
/*void backprop(neural_net *net, data_set *batch, double *delta_n_b, double ***delta_n_w);*/

#endif
