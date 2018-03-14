#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H
#include "libft/libft.h"
#include <math.h>

/*ACTF_N counts the number of activation functions in this file*/
#define ACTF_N 5 /*to update every time an actf is added here*/

double (*get_actf(char *name))(double x);
char *get_actf_name(double (*actf)(double x));
int actf_i(double (*actf)(double x));
char *i_actf(int i);
double identity(double x);
double binary_step(double x);
double logistic(double x);
double soft_sign(double x);
double ReLU(double x);

#endif
