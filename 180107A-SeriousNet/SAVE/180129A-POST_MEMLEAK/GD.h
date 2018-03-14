#ifndef GD_H
#define GD_H
#include "neural_struct.h"
#include "data_processing.h"
#include "learning.h"
#include "evaluate.h"

void GD(neural_net *net, data_set *training_data, data_set *test_data, double l_rate);

#endif
