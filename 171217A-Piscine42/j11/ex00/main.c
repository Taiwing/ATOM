#include "libft/libft.h"
#include "ft_list.h"

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

  t_list *elem;

  elem = ft_create_elem(tab[0]);
  ft_putstr(elem->data);
  ft_putchar('\n');

  return 0;
}
