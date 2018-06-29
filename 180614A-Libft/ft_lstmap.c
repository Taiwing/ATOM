#include "libf4.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *ptr;

	ret = lst ? (*f)(lst) : NULL;
	ptr = ret;
	while (lst && lst->next)
	{
		ptr->next = (*f)(lst->next);
		ptr = ptr->next;
		lst = lst->next;
	}
	return ret;
}
