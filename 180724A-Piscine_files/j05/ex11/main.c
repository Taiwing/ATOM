#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_str_is_uppercase.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("ft_str_is_uppercase: %d\n", ft_str_is_uppercase(argv[1]));

  return EXIT_SUCCESS;
}
