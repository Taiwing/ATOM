#include "libft/libft.h"
#include "ft_bouton.h"

int main(int argc, char *argv[])
{
  if(argc != 4)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;

  i = ft_bouton(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));

  ft_putnbr_base(i, "0123456789");
  ft_putchar('\n');

  return 0;
}
