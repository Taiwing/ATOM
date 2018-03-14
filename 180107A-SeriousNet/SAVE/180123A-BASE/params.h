#ifndef PARAMS_H
#define PARAMS_H
#include <stdlib.h>
#include "libft/libft.h"
#include "config.h"

int get_params(char **name, int *num_layers, int *sizes, char *av[]);
int param_error(char *name, int num_layers, int *sizes);

/*  command examples:
**    sn handy
**    sn bob -l 3 -s 3 2 1
**
**  -l: --layers (defines num_layers)
**  -s: --sizes (defines the sizes array)
*/

/*  TO DO:
**  -a: --all (defines a default value for the width of the layers)
**  -e: --exception (defines individual values for th sizes array)
**  -i: --input (defines the width of the input layer (same as -e 0 X))
**  -o: --output (defines the width of the output layer)
*/

#endif
