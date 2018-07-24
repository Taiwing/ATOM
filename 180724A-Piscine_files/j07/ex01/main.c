#include "libft/libft.h"
#include "ft_range.h"

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int min;
  int max;
  int i;
  int *tab;

  min = ft_atoi(argv[1]);
  max = ft_atoi(argv[2]);
  i = 0;
  tab = ft_range(min, max);

  while(i < (max - min))
  {
    ft_putnbr_base(tab[i], "0123456789");
    ft_putchar('\n');
    i++;
  }

  return 0;
}
