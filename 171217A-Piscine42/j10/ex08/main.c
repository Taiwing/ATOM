#include "libft/libft.h"
#include "ft_advanced_sort_wordtab.h"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  char **tab;

  i = 1;
  tab = (char **)malloc(argc * sizeof(char *));

  while(i <= argc)
  {
    tab[i-1] = i == argc ? 0 : ft_strdup(argv[i]);
    i++;
  }

  ft_advanced_sort_wordtab(tab, &ft_strcmp);
  ft_print_words_tables(tab);

  return 0;
}
