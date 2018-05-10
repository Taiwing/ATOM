#include "libft.h"

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
  void *data;
  t_list *ptr[2];

  ptr[0] = *begin_list;

  while(ptr[0])
  {
    ptr[1] = ptr[0];
    while(ptr[1])
    {
      if((*cmp)(ptr[0]->data, ptr[1]->data) > 0)
      {
        data = ptr[0]->data;
        ptr[0]->data = ptr[1]->data;
        ptr[1]->data = data;
      }
      ptr[1] = ptr[1]->next;
    }
    ptr[0] = ptr[0]->next;
  }
}
