#include "activation_functions.h"

double identity(double x)
{
  return x;
}

double binary_step(double x)
{
  return (x < 0 ? 0 : 1);
}

double logistic(double x)
{
  return (1.0/(1.0+exp(-x)));
}

double soft_sign(double x)
{
  return (x/(1+fabs(x)));
}

double ReLU(double x)
{
  return (x < 0 ? 0 : x);
}
