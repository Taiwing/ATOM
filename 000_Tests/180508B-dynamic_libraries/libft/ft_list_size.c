#include "libft.h"

int ft_list_size(t_list *begin_list)
{
  int size;
  t_list *ptr;

  size = 0;
  ptr = begin_list;

  while(ptr)
  {
    ptr = ptr->next;
    size++;
  }

  return size;
}
