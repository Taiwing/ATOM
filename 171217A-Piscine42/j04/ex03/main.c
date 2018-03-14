#include <stdio.h>
#include "libft/libft.h"
#include "ft_recursive_power.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  int nb;
  int power;

  nb = ft_atoi(argv[1]);
  power = ft_atoi(argv[2]);

  printf("%d^%d = %d\n", nb, power, ft_recursive_power(nb, power));

  return EXIT_SUCCESS;
}
