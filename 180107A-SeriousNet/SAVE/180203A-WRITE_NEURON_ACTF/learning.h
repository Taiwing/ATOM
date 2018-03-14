#ifndef LEARNING_H
#define LEARNING_H
#include "neural_struct.h"
#include "data_processing.h"
#include "derivative_functions.h"

void back_propagation(neural_net *net, double *expout, double l_rate);
void backprop_SGD(neural_net *net, double *expout, double **delta_b, double ***delta_w);
void *alloc_delta(neural_net *net, char c);
void free_delta(neural_net *net, double **delta_b, double ***delta_w);
void reset_delta(neural_net *net, double **delta_b, double ***delta_w);

#endif
