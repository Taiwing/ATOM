#include "libft.h"

void	ft_lst_reverse(t_list **lst)
{
	static t_list	*prev = 0;
	t_list			*next;

	if (!lst || !*lst)
		return ;
	next = (*lst)->next;
	(*lst)->next = prev;
	prev = *lst;
	if (next)
		ft_lst_reverse(&next);
	if (!(*lst)->next)
	{
		*lst = prev;
		prev = 0;
	}
}
