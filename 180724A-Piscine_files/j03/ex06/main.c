#include <stdio.h>
#include "libft/libft.h"
#include "ft_swap.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  int a;
  int b;

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  ft_swap(&a, &b);

  printf("a = %d\nb = %d\n", a, b);

  return EXIT_SUCCESS;
}
