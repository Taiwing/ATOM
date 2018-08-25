#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_convert_base.h"

int main(int argc, char **argv)
{
  if(argc != 4)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char *nbr;

  nbr = ft_convert_base(argv[1], argv[2], argv[3]);
  ft_putstr(nbr);
  ft_putchar('\n');

  return EXIT_SUCCESS;
}
