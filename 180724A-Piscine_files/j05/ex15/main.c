#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strlcat.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char dest[15];

  int i = 0;

  while(i < 7)
  {
    dest[i] = i + 48;
    i++;
  }
  dest[i] = '\0';

  printf("sizeof(dest): %li\n", sizeof(dest));
  printf("ft_strlcat: %d\n", ft_strlcat(dest, argv[1], sizeof(dest)));
  printf("result: %s\n", dest);

  return EXIT_SUCCESS;
}
