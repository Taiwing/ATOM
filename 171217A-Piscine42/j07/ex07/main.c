#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_split.h"
#include "ft_print_words_tables.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  int i;
  char **tab;

  i = 0;
  tab = ft_split(argv[1], argv[2]);

  ft_print_words_tables(tab);

  return EXIT_SUCCESS;
}
