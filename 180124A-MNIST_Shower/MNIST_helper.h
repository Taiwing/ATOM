#ifndef MNIST_HELPER_H
#define MNIST_HELPER_H
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>

void load_MNIST_bitmap(ALLEGRO_BITMAP **handy_number, int index, int test);
void load_MNIST_data(int index, unsigned char map[28][28], int test);
void show_MNIST_labels(int *index, int test);

#endif
