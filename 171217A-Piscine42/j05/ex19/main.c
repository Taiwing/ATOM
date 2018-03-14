#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_putstr_non_printable.h"

int main(int argc, char **argv)
{
  if(argc != 1)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char test[] = "Coucou\ntu vas bien ?";

  ft_putstr_non_printable(test);
  ft_putchar('\n');

  return EXIT_SUCCESS;
}
