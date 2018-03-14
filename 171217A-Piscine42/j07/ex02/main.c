#include "libft/libft.h"
#include "ft_ultimate_range.h"

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  int max;
  int min;
  int size;
  int *range;

  i = 0;
  min = ft_atoi(argv[1]);
  max = ft_atoi(argv[2]);
  size = ft_ultimate_range(&range, min, max);

  ft_putnbr_base(size, "0123456789");
  ft_putchar('\n');

  while(i < (max-min))
  {
    ft_putnbr_base(range[i], "0123456789");
    ft_putchar('\n');
    i++;
  }

  return 0;
}
