#include "ft_concat_params.h"
#include "libft/libft.h"
#include <stdlib.h>

static char *ft_alloc_concatarr(int argc, char **argv);

char *ft_concat_params(int argc, char **argv)
{
  int i;
  int j;
  int k;
  char *concat;

  i = 0;
  k = 0;
  concat = ft_alloc_concatarr(argc, argv);

  while(i < argc)
  {
    j = 0;
    while(argv[i][j])
    {
      concat[k] = argv[i][j];
      j++;
      k++;
    }
    concat[k] = i == argc-1 ? '\0' : '\n';
    k++;
    i++;
  }

  return concat;
}

static char *ft_alloc_concatarr(int argc, char **argv)
{
  int i;
  int j;
  int size;

  i = 0;
  size = 0;

  while(i < argc)
  {
    j = 0;
    while(argv[i][j])
      j++;
    size += j+1;
    i++;
  }

  return (char *)malloc(size * sizeof(char));
}
