#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strcmp.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  int ret;

  ret = ft_strcmp(argv[1], argv[2]);

  printf("ft_strcmp: %d\n", ret);

  return EXIT_SUCCESS;
}
