#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H
#include <math.h>

double identity(double x);
double binary_step(double x);
double logistic(double x);
double soft_sign(double x);
double ReLU(double x);

#endif
