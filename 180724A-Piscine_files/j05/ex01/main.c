#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strncpy.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char cpy[100];

  printf("copy: %s\n", ft_strncpy(cpy, argv[1], 10));

  return EXIT_SUCCESS;
}
