#include "ft_active_bits.h"

unsigned int ft_active_bits(int value)
{
  unsigned int bits;

  bits = 0;

  while(value)
  {
    bits = value%2 ? bits+1 : bits;
    value /= 2;
  }

  return bits;
}
