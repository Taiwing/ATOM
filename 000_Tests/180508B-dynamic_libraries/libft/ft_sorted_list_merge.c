#include "libft.h"

static void ft_place_element(t_list *elem, t_list **ptrList1, int (*cmp)());

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
  t_list *next2;
  t_list *ptrList2;
  t_list **ptrList1;

  ptrList2 = begin_list2;
  ptrList1 = begin_list1;

  while(ptrList2)
  {
    next2 = ptrList2->next;
    ft_place_element(ptrList2, ptrList1, cmp);
    ptrList2 = next2;
  }
}

static void ft_place_element(t_list *elem, t_list **ptrList1, int (*cmp)())
{
  t_list *host[2];

  host[0] = *ptrList1;
  host[1] = *ptrList1;

  while(host[1])
  {
    if((*cmp)(elem->data, host[1]->data) > 0)
    {
      host[1] = host[1]->next;
      host[0] = host[0]->next == host[1] ? host[0] : host[0]->next;
    }
    else
    {
      if(host[1] == host[0])
        *ptrList1 = elem;
      else
        host[0]->next = elem;
      break;
    }
    host[0]->next = !host[1] ? elem : host[0]->next;
  }
  elem->next = host[1];
}
