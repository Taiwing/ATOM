#include "libft.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
  t_list *ptr;

  ptr = begin_list;

  while(ptr)
  {
    (*f)(ptr->data);
    ptr = ptr->next;
  }
}

void ft_putdata(void *data)
{
  ft_putstr(data);
  ft_putchar('\n');
}
