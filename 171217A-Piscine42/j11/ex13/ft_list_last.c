#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
  t_list *ptr;

  ptr = begin_list;

  while(ptr->next)
    ptr = ptr->next;

  return ptr;
}
