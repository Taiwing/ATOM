#ifndef DERIVATIVE_FUNCTIONS_H
#define DERIVATIVE_FUNCTIONS_H
#include <math.h>
#include "activation_functions.h"

double (*get_prime(double (*actf)(double x)))(double x);
double identity_prime(double x);
double binary_step_prime(double x);
double logistic_prime(double x);
double soft_sign_prime(double x);
double ReLU_prime(double x);

#endif
