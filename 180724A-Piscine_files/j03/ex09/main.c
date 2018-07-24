#include <stdio.h>
#include "libft/libft.h"
#include "ft_sort_integer_table.h"

int main(int argc, char **argv)
{
  if(argc < 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  int *tab;

  tab = malloc((argc - 1) * sizeof(int));

  int i;

  i = 0;

  while(i < (argc - 1))
  {
    tab[i] = ft_atoi(argv[i + 1]);
    i++;
  }

  ft_sort_integer_table(tab, argc - 1);

  i = 0;

  while(i < (argc - 1))
  {
    printf("%d\n", tab[i]);
    i++;
  }

  return EXIT_SUCCESS;
}
