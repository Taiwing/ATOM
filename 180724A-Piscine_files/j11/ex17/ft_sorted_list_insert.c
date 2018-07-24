#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
  t_list *elem;
  t_list *ptr[2];

  elem = ft_create_elem(data);
  ptr[0] = *begin_list;
  ptr[1] = *begin_list;

  while(ptr[1])
  {
    if((*cmp)(elem->data, ptr[1]->data) > 0)
    {
      ptr[1] = ptr[1]->next;
      ptr[0] = ptr[0]->next == ptr[1] ? ptr[0] : ptr[0]->next;
    }
    else
    {
      if(ptr[1] == ptr[0])
        *begin_list = elem;
      else
        ptr[0]->next = elem;
      break;
    }
    ptr[0]->next = !ptr[1] ? elem : ptr[0]->next;
  }
  elem->next = ptr[1];
}
