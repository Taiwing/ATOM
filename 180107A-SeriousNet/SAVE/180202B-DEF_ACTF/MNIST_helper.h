#ifndef MNIST_HELPER_H
#define MNIST_HELPER_H
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "data_processing.h"

void get_MNIST_data_set(data_set **training, data_set **test);
void load_MNIST_bitmap(ALLEGRO_BITMAP **handy_number, int index, int test);
void load_MNIST_data(int index, unsigned char map[28][28], int test);
void show_MNIST_labels(int *index, int test);
int get_MNIST_label(int index, int test);

#endif
