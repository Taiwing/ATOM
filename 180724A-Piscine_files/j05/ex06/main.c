#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strlowcase.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("ft_strlowcase: %s\n", ft_strlowcase(argv[1]));

  return EXIT_SUCCESS;
}
