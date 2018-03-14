#ifndef PARAMS_H
#define PARAMS_H
#include <stdlib.h>
#include "libft/libft.h"
#include "config.h"

char *get_params(int ac, char *av[], int param_arr[4]);
int param_error(char *name, int num_layers, int *sizes, char **actf);

/*  command examples:
**    sn handy
**    sn bob -l 3 -s 3 2 1
**    sn looolz -l 6 -s 6 5 4 3 2 1 -f ReLU
**
**  -l: --layers (defines num_layers)
**  -s: --sizes (defines the sizes array)
**  -f: --function (defines the activation function of the net)
**  -p: --print (prints the net file)
**  -e: --evaluate (uses test_data to rate the net's efficacy)
**  -t: --train (train the network, takes the method in argument)
*/

/* TODO*/
/*
**  -u: --use (feeds the network whith chosen or random data) (make it possible to load data from a file or the command line)
*/

#endif
