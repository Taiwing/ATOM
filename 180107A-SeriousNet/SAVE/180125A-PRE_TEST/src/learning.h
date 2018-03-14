#ifndef LEARNING_H
#define LEARNING_H
#include "neural_struct.h"
#include "data_processing.h"
#include "derivative_functions.h"

int expected_output(neuron **O_layer, double *expout, int size);
void backprop(neural_net *net, data_set *batch, double **delta_n_b, double ***delta_n_w, int set_pos);
void save_weights(neural_net *net);

#endif
