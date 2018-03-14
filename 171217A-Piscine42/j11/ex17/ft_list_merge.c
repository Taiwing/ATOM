#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
  t_list *ptr;

  ptr = *begin_list1;

  if(*begin_list1)
  {
    while(ptr->next)
      ptr = ptr->next;

    ptr->next = begin_list2;
  }
  else
    *begin_list1 = begin_list2;
}
