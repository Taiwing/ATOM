#ifndef EVALUATE_H
#define EVALUATE_H
#include "neural_struct.h"
#include "data_processing.h"

int evaluate(neural_net *net, data_set *test_data);
int expected_output(neuron **O_layer, double *expout, int size);
int expected_output_16N3(neuron **O_layer, double *expout, int size);

#endif
