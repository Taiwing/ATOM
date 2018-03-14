#ifndef TRAINING_H
#define TRAINING_H
#include "data_helper.h"
#include "GD.h"
#include "SGD.h"

void train_network(neural_net *net, char method, double l_rate);

#endif
