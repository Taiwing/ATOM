#include "libft.h"

void ft_list_clear(t_list **begin_list)
{
  t_list *ptr[2];

  ptr[0] = *begin_list;

  while(ptr[0]->next)
  {
    ptr[1] = ptr[0]->next;
    free(ptr[0]);
    ptr[0] = ptr[1];
  }

  *begin_list = NULL;
}
