#include "derivative_functions.h"

double (*get_prime(double (*actf)(double x)))(double x)
{
  if(actf == &identity)
    return &identity_prime;
  else if(actf == &binary_step)
    return &binary_step_prime;
  else if(actf == &logistic)
    return &logistic_prime;
  else if(actf == &soft_sign)
    return &soft_sign_prime;
  else if(actf == &ReLU)
    return &ReLU_prime;
  else
    return 0;
}

double identity_prime(double x)
{
  return 1 + (x * 0);
}

double binary_step_prime(double x)
{
  return 0 * x;
}

double logistic_prime(double x)
{
  return (logistic(x) * (1 - logistic(x)));
}

double soft_sign_prime(double x)
{
  return (1/(1+(fabs(x) * fabs(x))));
}

double ReLU_prime(double x)
{
  return (x < 0 ? 0 : 1);
}
