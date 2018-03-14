#include "ft_do-op.h"
#include "ft_utils.h"

int main(int argc, char *argv[])
{
  if(argc != 4)
    return 1;

  int *num[3];
  int a;
  int b;
  int c;

  num[0] = &a;
  num[1] = &b;
  num[2] = &c;
  a = ft_get_num(argv[1]);
  b = ft_get_num(argv[3]);
  ft_doop(num, ft_find_op(argv[2][0]));

  if(num[2])
  {
    ft_putnbr(*(num[2]));
    ft_putstr("\n");
  }

  return 0;
}
