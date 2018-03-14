#include <stdio.h>
#include <stdlib.h>
#include "ft_ultimate_div_mod.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }
  else
  {
    int *a;
    int *b;

    a = malloc(sizeof(int));
    b = malloc(sizeof(int));

    *a = atoi(argv[1]);
    *b = atoi(argv[2]);

    ft_ultimate_div_mod(a, b);

    printf("div = %d\nmod = %d\n", *a, *b);
  }

  return EXIT_SUCCESS;
}
