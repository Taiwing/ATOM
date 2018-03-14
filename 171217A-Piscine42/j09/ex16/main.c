#include "libft/libft.h"
#include "ft_active_bits.h"

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int ret;

  ret = ft_active_bits(ft_atoi(argv[1]));

  ft_putnbr_base(ret, "0123456789");
  ft_putstr(" active bits.\n");

  return 0;
}
