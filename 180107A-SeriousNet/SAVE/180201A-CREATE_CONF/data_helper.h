#ifndef DATA_HELPER_H
#define DATA_HELPER_H
#include <stdio.h>
#include <stdlib.h>
#include "data_processing.h"
#include "MNIST_helper.h"

void get_data(char *name, data_set **training_data, data_set **test_data, int train_s, int test_s);
void get_424_data_set(data_set **training, data_set **test, int train_s, int test_s);
void get_16N3_data_set(data_set **training, data_set **test, int train_s, int test_s);
void get_16N3C_data_set(data_set **training, data_set **test, int train_s, int test_s);

#endif
