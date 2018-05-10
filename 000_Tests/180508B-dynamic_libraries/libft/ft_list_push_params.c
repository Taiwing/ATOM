#include "libft.h"

t_list *ft_list_push_params(int ac, char **av)
{
  int i;
  t_list *list;
  t_list *ptr;

  i = 1;
  list = ft_create_elem(av[0]);
  ptr = list;

  while(i < ac)
  {
    ptr->next = ft_create_elem(av[i]);
    ptr = ptr->next;
    i++;
  }

  return list;
}
