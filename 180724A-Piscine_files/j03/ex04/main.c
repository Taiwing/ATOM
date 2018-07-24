#include <stdio.h>
#include "libft/libft.h"
#include "ft_putstr.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  ft_putstr(argv[1]);
  ft_putchar('\n');

  return EXIT_SUCCESS;
}
