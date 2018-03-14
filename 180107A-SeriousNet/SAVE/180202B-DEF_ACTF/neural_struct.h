#ifndef NEURAL_STRUCT_H
#define NEURAL_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "activation_functions.h"

enum conf {ACT_F, NUM_LAYERS, SIZES, BIASES, WEIGHTS};

typedef struct neuron
{
  double input;
  double output;
  double (*actf)(double x);
} neuron;

typedef struct neural_net
{
  char *name;                                                                   /*name of the net, and of its conf file (name.nn)*/
  int num_layers;                                                               /*is the index of the neural layer sizes array*/
  int *sizes;                                                                   /*is the actual array of sizes*/
  double **biases;                                                              /*arr[num_layers-1][sizes] starts at the 2nd layer*/
  double ***weights;                                                            /*arr[num_layers-1][sizes[i]][sizes[i+1]]*/
  neuron ***layers;                                                             /*arr[num_layers][sizes]*/
  double (*def_actf)(double x);                                                 /*pointer to the default activation function of the net*/
} neural_net;

neural_net *construct_neural_net(char *name);
void alloc_weights(neural_net *net);
void alloc_layers(neural_net *net);
void free_net(neural_net *net);

#endif
