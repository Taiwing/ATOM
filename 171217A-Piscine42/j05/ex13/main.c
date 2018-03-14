#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strcat.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char dest[100];

  int i = 0;

  while(i < 7)
  {
    dest[i] = '0';
    i++;
  }
  dest[i] = '\0';

  printf("ft_strcat: %s\n", ft_strcat(dest, argv[1]));

  return EXIT_SUCCESS;
}
