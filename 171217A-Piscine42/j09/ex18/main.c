#include "libft/libft.h"
#include "ft_join.h"

int main(int argc, char *argv[])
{
  if(argc < 3)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  char **tab;
  char *joined;

  i = 0;
  tab = (char **)malloc((argc-1) * sizeof(char *));

  while(i <= argc-2)
  {
    tab[i] = i != argc-2 ? argv[i+1] : 0;
    i++;
  }

  joined = ft_join(tab, argv[argc-1]);

  ft_putstr(joined);
  ft_putchar('\n');

  return 0;
}
