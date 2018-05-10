#include "libft.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
  t_list *ptr;
  t_list *elem;

  elem = ft_create_elem(data);

  if(!(*begin_list))
    *begin_list = elem;
  else
  {
    ptr = *begin_list;

    while(ptr->next)
      ptr = ptr->next;

    ptr->next = elem;
  }
}
