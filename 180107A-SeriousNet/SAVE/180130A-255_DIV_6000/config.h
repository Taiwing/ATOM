#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libft/libft.h"

void create_conf(char *conf, int num_layers, int *sizes, char *actf);
double rand_double(double min, double max);
char *get_conf_name(char *name);
int does_config_exist(char *name);

/*TODO*/
/*
** remake the config system with new configurable parameters:
**  - each and every neuron must be given an activation function (which also
**  means modifying neural_struct.h to include *f pointers in each neuron)
**  - make the cost function paramater (also include a pointer to the cost
**  function in the neural_net structure, and create the derivatives)
**  - also maybe include parameters such as the default learning algorithm, the
**  default learning rate, and maybe even the default values for the parameters
**  of these algorithms (like mini_batch_size and epochs)
**  - mabe make different paramater files, one for the entire program wich would
**  set the default values for each algorithms
*/

#endif
