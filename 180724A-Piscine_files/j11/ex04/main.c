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

  t_list *first;

  first = ft_create_elem(tab[0]);
  ft_list_push_front(&first, tab[1]);

  ft_putstr(first->data);
  ft_putchar('\n');
  ft_putstr(first->next->data);
  ft_putchar('\n');
  ft_putnbr(ft_list_size(first));
  ft_putchar('\n');
  ft_putstr(ft_list_last(first)->data);
  ft_putchar('\n');

  return 0;
}
