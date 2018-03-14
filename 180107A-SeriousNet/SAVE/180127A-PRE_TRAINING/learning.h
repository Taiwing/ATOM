#ifndef LEARNING_H
#define LEARNING_H
#include "neural_struct.h"
#include "data_processing.h"
#include "derivative_functions.h"

void backprop(neural_net *net, data_set *batch, double **delta_n_b, double ***delta_n_w, int set_pos);
void save_weights(neural_net *net);

void back_propagation(neural_net *net, double *expout, double l_rate);
void *alloc_delta(neural_net *net, char c);

#endif
