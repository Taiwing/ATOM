#include "libft.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
  t_list *ptr[2];

  ptr[0] = *begin_list;
  ptr[1] = *begin_list;

  while(ptr[1])
  {
    if((*cmp)(ptr[1]->data, data_ref))
    {
      if(ptr[1] == *begin_list)
        *begin_list = (*begin_list)->next;
      else
        ptr[0]->next = ptr[1]->next;
      free(ptr[1]);
    }
    ptr[1] = ptr[0]->next;
    ptr[0] = ptr[0]->next == ptr[1] ? ptr[0] : ptr[0]->next;
  }
}
