#include "libft.h"

void	ft_lst_remove_if(t_list **lst, void *content_ref, int (*cmp)())
{
	static t_list	*prev = 0;
	t_list			*next;
	t_list			*cur;

	if (!lst || !*lst || !content_ref || !cmp)
		return ;
	cur = *lst;
	next = cur->next;
	if ((*cmp)(content_ref, cur->content) == 0)
	{
		free(cur);
		cur = 0;
		if (prev)
			prev->next = next;
		else
			*lst = next;
	}
	prev = cur ? cur : prev;
	if (next)
		ft_lst_remove_if(&next, content_ref, cmp);
	else
		prev = 0;
}
