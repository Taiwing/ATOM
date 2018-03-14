#ifndef PARAMS_H
#define PARAMS_H
#include <stdlib.h>
#include "libft/libft.h"
#include "config.h"

int get_params(char **name, int *num_layers, int *sizes, char *av[]);
int param_error(char *name, int num_layers, int *sizes, char **actf);

/*  command examples:
**    sn handy
**    sn bob -l 3 -s 3 2 1
**    sn looolz -l 6 -s 6 5 4 3 2 1 -f ReLU
**
**  -l: --layers (defines num_layers)
**  -s: --sizes (defines the sizes array)
**  -f: --function (defines the activation function of the net)
*/

/*  TODO:
**  -a: --all (defines a default value for the width of the layers)
**  -e: --exception (defines individual values for th sizes array)
**  -i: --input (defines the width of the input layer (same as -e 0 X))
**  -o: --output (defines the width of the output layer)
*/

#endif
