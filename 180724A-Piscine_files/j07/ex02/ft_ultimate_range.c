#include "ft_ultimate_range.h"
#include "libft/libft.h"
#include <stdlib.h>

static int **alloc_2D_array(int w, int h);

int ft_ultimate_range(int **range, int min, int max)
{
  int i;

  *range = (max - min) > 0 ? malloc((max - min) * sizeof(int)) : NULL;
  i = 0;

  while(min < max)
  {
    (*range)[i] = min;
    min++;
    i++;
  }

  return sizeof(*range);
}

static int **alloc_2D_array(int w, int h)
{
  int i;
  int** arr;
  arr = malloc(w * sizeof(int*));

  if(arr == NULL)
    ft_putstr("ERROR: out of memory\n");

  i = 0;

  while(i < w)
  {
    arr[i] = malloc(h * sizeof(int));

    if(arr[i] == NULL)
      exit(EXIT_FAILURE);

    i++;
  }

  return arr;
}
