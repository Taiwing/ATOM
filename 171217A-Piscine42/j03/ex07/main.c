#include <stdio.h>
#include "libft/libft.h"
#include "ft_strrev.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  printf("%s\n", ft_strrev(argv[1]));

  return EXIT_SUCCESS;
}
