#include "libft.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
  unsigned int i;
  t_list *ptr;

  i = 0;
  ptr = nbr ? begin_list : NULL;

  while(ptr && i < nbr)
  {
    ptr = ptr->next;
    i++;
  }

  return ptr;
}
