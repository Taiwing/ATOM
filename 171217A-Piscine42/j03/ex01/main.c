#include <stdio.h>
#include <stdlib.h>
#include "ft_ultimate_ft.h"

int main()
{
  int *********nbr;

  nbr = malloc(sizeof(int*));
  *nbr = malloc(sizeof(int**));
  **nbr = malloc(sizeof(int***));
  ***nbr = malloc(sizeof(int****));
  ****nbr = malloc(sizeof(int*****));
  *****nbr = malloc(sizeof(int******));
  ******nbr = malloc(sizeof(int*******));
  *******nbr = malloc(sizeof(int********));
  ********nbr = malloc(sizeof(int*********));

  ft_ultimate_ft(nbr);

  printf("%d\n", nbr[0][0][0][0][0][0][0][0][0]);

  return EXIT_SUCCESS;
}
