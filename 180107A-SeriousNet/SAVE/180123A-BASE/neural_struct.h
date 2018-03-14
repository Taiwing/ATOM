#ifndef NEURAL_STRUCT_H
#define NEURAL_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "config.h"

enum conf {NUM_LAYERS, SIZES, BIASES, WEIGHTS};

typedef struct neuron
{
  double input;
  double output;
} neuron;

typedef struct neural_net
{
  char *name;        /*identifies the network, and its conf file (name.nn)*/
  int num_layers;    /*is the index of the neural layer sizes array*/
  int *sizes;        /*is the actual array of sizes*/
  double *biases;    /*array of arr[num_layers-1][sizes]*/ /*TO DO: CHANGE THE DIMENSION OF THE BIASES ARRAY*/
  double ***weights; /*array of arr[num_layers-1][sizes[i]][sizes[i+1]]*/
  neuron ***layers;  /*array of arr[num_layers][sizes]*/
  /*TO DO: ADD A FUNCTION POINTER TO THE ACTIVATION FUNCTION*/
  /*double (*actf)(double x);*/
} neural_net;

neural_net *construct_neural_net(char *name);
void alloc_weights(neural_net *net);
void alloc_layers(neural_net *net);
void get_conf_data(char *conf, int param, neural_net *net);

#endif
