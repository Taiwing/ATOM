#include "libft.h"

void	ft_lst_move_front(t_list **lst, t_list *elem)
{
	t_list *prev;

	if (!lst || !*lst || !elem || *lst == elem)
		return ;
	prev = *lst;
	while (prev && prev->next != elem)
		prev = prev->next;
	if (!prev)
		return ;
	prev->next = elem->next;
	elem->next = *lst;
	*lst = elem;
}	
