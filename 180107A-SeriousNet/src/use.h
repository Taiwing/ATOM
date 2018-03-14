#ifndef USE_H
#define USE_H
#include "neural_struct.h"
#include "data_processing.h"

void use_network(neural_net *net, data_set *set);
/*TODO: load_data_set creates the appropriate data_set from user input maybe put in data_helper.c*/
//int load_data_set(double **raw_data);

#endif
