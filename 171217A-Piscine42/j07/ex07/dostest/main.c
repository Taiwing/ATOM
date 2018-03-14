#include "libft/libft.h"

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  char **tab;

  i = 0;
  tab = ft_split(argv[1], argv[2]);

  ft_print_words_tables(tab);

  return 0;
}
