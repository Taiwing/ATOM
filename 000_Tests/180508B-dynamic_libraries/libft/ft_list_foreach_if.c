#include "libft.h"

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
  t_list *ptr;

  ptr = begin_list;

  while(ptr)
  {
    if((*cmp)(ptr->data, data_ref))
      (*f)(ptr->data);
    ptr = ptr->next;
  }
}
