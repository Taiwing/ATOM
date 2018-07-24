#include "ft_alloc_2D_array.h"

int **ft_alloc_2D_array(int w, int h)
{
  int i;
  int** numbers;
  numbers = malloc(w * sizeof(int*));

  if(numbers == NULL)
  {
    printf("ERROR: out of memory\n");
  }

  i = 0;

  while(i < w)
  {
    numbers[i] = malloc(h * sizeof(int));

    if(numbers[i] == NULL)
      exit(EXIT_FAILURE);

    i++;
  }

  return numbers;
}
