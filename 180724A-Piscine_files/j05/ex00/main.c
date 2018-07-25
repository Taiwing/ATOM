#include <stdio.h>
#include <stdlib.h>
#include "ft_strcpy.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char cpy[100];

  ft_strcpy(cpy, argv[1]);

  printf("copy: %s\n", ft_strcpy(cpy, argv[1]));

  return EXIT_SUCCESS;
}
