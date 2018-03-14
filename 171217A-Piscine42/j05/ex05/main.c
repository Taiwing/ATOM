#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strupcase.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("ft_strupcase: %s\n", ft_strupcase(argv[1]));

  return EXIT_SUCCESS;
}
