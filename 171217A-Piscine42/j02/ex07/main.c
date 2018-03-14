#include "ft_print_combn.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }
  else
    ft_print_combn(atoi(argv[1]));

  return EXIT_SUCCESS;
}
