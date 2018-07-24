#include <stdio.h>
#include <stdlib.h>
#include "ft_ft.h"

int main()
{
  int *nbr;

  nbr = malloc(sizeof(int));

  ft_ft(nbr);

  printf("%d\n", *nbr);

  return EXIT_SUCCESS;
}
