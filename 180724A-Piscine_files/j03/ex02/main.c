#include <stdio.h>
#include <stdlib.h>
#include "ft_div_mod.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }
  else
  {
    int *d;
    int *m;

    d = malloc(sizeof(int));
    m = malloc(sizeof(int));

    ft_div_mod(atoi(argv[1]), atoi(argv[2]), d, m);

    printf("div = %d\nmod = %d\n", *d, *m);
  }

  return EXIT_SUCCESS;
}
