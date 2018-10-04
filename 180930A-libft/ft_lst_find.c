#include "libft.h"

t_list	*ft_lst_find(t_list *lst, void *content_ref, int (*cmp)())
{
	if (!lst || !content_ref || !cmp)
		return (0);
	while (lst)
	{
		if ((*cmp)(content_ref, lst->content) == 0)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
