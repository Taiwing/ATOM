#ifndef SGD_H
#define SGD_H
#include "data_processing.h"

void SGD(neural_net *net, data_set *training_data, int epochs, int mini_batch_size, double l_rate, data_set *test_data);
void random_shuffle(data_set *training_data, int i);
data_set **get_batches(data_set *t_data, int mbs);
void update_mini_batch(neural_net *net, data_set *batch, double l_rate);
int evaluate(neural_net *net, data_set *test_data); /*MAYBE TO MOVE*/

#endif
