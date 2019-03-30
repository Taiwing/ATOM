#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;

	ptr = lst && f ? f(lst) : NULL;
	if (ptr)
		ptr->next = ft_lstmap(lst->next, f);
	return (ptr);
}
