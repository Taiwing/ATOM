#include "libft.h"

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
  t_list *ptr;

  ptr = begin_list;

  while(ptr)
  {
    if((*cmp)(ptr->data, data_ref))
      return ptr;
    ptr = ptr->next;
  }

  return NULL;
}
