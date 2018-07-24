#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_atoi_base.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("%d\n", ft_atoi_base(argv[1], argv[2]));

  return EXIT_SUCCESS;
}
