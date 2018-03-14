#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H
#include "libft/libft.h"
#include <math.h>

double (*get_actf(char *name))(double x);
char *get_actf_name(double (*actf)(double x));
double identity(double x);
double binary_step(double x);
double logistic(double x);
double soft_sign(double x);
double ReLU(double x);

#endif
