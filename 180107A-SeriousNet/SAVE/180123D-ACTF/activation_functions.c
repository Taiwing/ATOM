#include "activation_functions.h"

double (*get_actf(char *name))(double x)
{
  if(!ft_strcmp(name, "identity"))
    return &identity;
  else if(!ft_strcmp(name, "binary_step"))
    return &binary_step;
  else if(!ft_strcmp(name, "logistic"))
    return &logistic;
  else if(!ft_strcmp(name, "soft_sign"))
    return &soft_sign;
  else if(!ft_strcmp(name, "ReLU"))
    return &ReLU;
  else
    return &logistic;
}

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
