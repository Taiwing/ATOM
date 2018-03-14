#ifndef NEURAL_STRUCT_H
#define NEURAL_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "config.h"
#include "activation_functions.h"

enum conf {ACT_F, NUM_LAYERS, SIZES, BIASES, WEIGHTS};

typedef struct neuron
{
  double input;
  double output;
} neuron;

typedef struct neural_net
{
  char *name;               /*name of the net, and of its conf file (name.nn)*/
  int num_layers;           /*is the index of the neural layer sizes array*/
  int *sizes;               /*is the actual array of sizes*/
  double **biases;          /*arr[num_layers-1][sizes] starts at the 2nd layer*/
  double ***weights;        /*arr[num_layers-1][sizes[i]][sizes[i+1]]*/
  neuron ***layers;         /*arr[num_layers][sizes]*/
  double (*actf)(double x); /*pointer to the activation function*/
} neural_net;

neural_net *construct_neural_net(char *name);
void alloc_weights(neural_net *net);
void alloc_layers(neural_net *net);
void get_conf_data(char *conf, int param, neural_net *net);

/*TEMPORARY*/
void create_format_conf(neural_net *net); /*is gonna create a conf file at the new format*/

#endif
