#include "libft.h"

void	ft_lst_remove_if(t_list **lst, void *content_ref, int (*cmp)())
{
	t_list  *prev;
	t_list	*cur;
	t_list	*next;

	if (!lst || !*lst || !cmp)
		return ;
	prev = NULL;
	cur = *lst;
	next = cur->next;
	while (cur)
	{
		if (!cmp(content_ref, cur->content))
		{
			ft_memdel((void **)&cur);
			if (prev)
				prev->next = next;
			else
				*lst = next;
		}
		prev = cur ? cur : prev;
		cur = next;
		next = cur ? cur->next : next;
	}
}
