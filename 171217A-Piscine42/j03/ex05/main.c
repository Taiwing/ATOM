#include <stdio.h>
#include "libft/libft.h"
#include "ft_strlen.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("%d\n", ft_strlen(argv[1]));

  return EXIT_SUCCESS;
}
