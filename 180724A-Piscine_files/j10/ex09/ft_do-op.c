#include "ft_do-op.h"
#include "ft_opp.h"

void ft_doop(int *num[3], int(*op)(int, int))
{
  if(!op)
    *(num[2]) = 0;
  else if(!(*(num[1])) && op ==  &ft_div)
  {
    num[2] = 0;
    ft_putstr("Stop : division by zero\n");
  }
  else if(!(*(num[1])) && op ==  &ft_mod)
  {
    num[2] = 0;
    ft_putstr("Stop : modulo by zero\n");
  }
  else if(op == &ft_usage)
  {
    num[2] = 0;
    (*op)(*(num[0]), *(num[1]));
  }
  else
    *(num[2]) = (*op)(*(num[0]), *(num[1]));
}

int (*ft_find_op(char sym))(int, int)
{
  int i;

  i = 0;

  while(i < 5)
  {
    if(sym == gl_opptab[i].op[0])
      return gl_opptab[i].f;
    i++;
  }

  return gl_opptab[i].f;
}
