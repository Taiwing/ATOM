#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_print_memory.h"

int main(int argc, char **argv)
{
  if(argc != 1)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char test[] = "Salut les aminches c'est cool show mem on fait de truc terrible.\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  ft_print_memory(test, sizeof(test));

  return EXIT_SUCCESS;
}
