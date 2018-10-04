#include "libft.h"

void	ft_lst_push_back(t_list **lst, void *content, size_t content_size)
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr && ptr->next)
		ptr = ptr->next;
	if (ptr)
		ptr->next = ft_lstnew(content, content_size);
	else
		*lst = ft_lstnew(content, content_size);
}
