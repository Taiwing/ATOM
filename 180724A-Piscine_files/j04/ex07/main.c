#include <stdio.h>
#include "libft/libft.h"
#include "ft_find_next_prime.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("%d\n", ft_find_next_prime(ft_atoi(argv[1])));

  return EXIT_SUCCESS;
}
