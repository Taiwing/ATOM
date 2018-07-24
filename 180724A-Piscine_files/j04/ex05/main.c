#include <stdio.h>
#include "libft/libft.h"
#include "ft_sqrt.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("sqrt(%d) = %d\n", ft_atoi(argv[1]), ft_sqrt(ft_atoi(argv[1])));

  return EXIT_SUCCESS;
}
