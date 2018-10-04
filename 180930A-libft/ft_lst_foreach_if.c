#include "libft.h"

void	ft_lst_foreach_if(t_list *lst, void (*f)(void *),
		void *content_ref, int (*cmp)())
{
	while (lst)
	{
		if ((*cmp)(content_ref, lst->content) == 0)
			(*f)(lst->content);
		lst = lst->next;
	}
}
