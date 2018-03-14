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

char *get_actf_name(double (*actf)(double x))
{
  if(actf == &identity)
    return "identity";
  else if(actf == &binary_step)
    return "binary_step";
  else if(actf == &logistic)
    return "logistic";
  else if(actf == &soft_sign)
    return "soft_sign";
  else if(actf == &ReLU)
    return "ReLU";
  else
    return 0;
}

int actf_i(double (*actf)(double x))
{
  if(actf == &identity)
    return 0;
  else if(actf == &binary_step)
    return 1;
  else if(actf == &logistic)
    return 2;
  else if(actf == &soft_sign)
    return 3;
  else if(actf == &ReLU)
    return 4;
  else
    return -1;
}

char *i_actf(int i)
{
  if(i == 0)
    return "identity";
  else if(i == 1)
    return "binary_step";
  else if(i == 2)
    return "logistic";
  else if(i == 3)
    return "soft_sign";
  else if(i == 4)
    return "ReLU";
  else
    return 0;
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
