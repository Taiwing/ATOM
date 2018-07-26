#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strlcpy.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char dest[15];

  printf("sizeof(dest): %lu\n", sizeof(dest));
  printf("ft_strlcpy: %d\n", ft_strlcpy(dest, argv[1], sizeof(dest)));
  printf("result: %s\n", dest);

  return EXIT_SUCCESS;
}
