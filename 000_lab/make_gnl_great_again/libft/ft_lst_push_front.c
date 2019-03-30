#include "libft.h"

void	ft_lst_push_front(t_list **lst, void *content, size_t content_size)
{
	ft_lstadd(lst, ft_lstnew(content, content_size));
}
