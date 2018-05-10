#include "libft.h"

void ft_list_reverse(t_list **begin_list)
{
  int i;
  int length;
  void *data;
  t_list *ptr[2];

  length = ft_list_size(*begin_list)-1;
  ptr[0] = *begin_list;
  ptr[1] = *begin_list;

  while(length > 0)
  {
    i = 0;
    ptr[1] = ptr[0];
    while(i < length)
    {
      ptr[1] = ptr[1]->next;
      i++;
    }
    data = ptr[0]->data;
    ptr[0]->data = ptr[1]->data;
    ptr[1]->data = data;
    ptr[0] = ptr[0]->next;
    length -= 2;
  }
}
