#include "ft_abs.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  ft_putnbr_base(abs(ft_atoi(argv[1])), "0123456789");
  ft_putchar('\n');

  return 0;
}
