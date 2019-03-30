#include "libft.h"

void	ft_lst_sort(t_list **lst, int (*cmp)())
{
	t_list	*cur;
	t_list	*ptr;
	void	*content;
	size_t	content_size;

	cur = *lst;
	while (cur && cur->next)
	{
		ptr = cur->next;
		while (ptr)
		{
			if ((*cmp)(cur->content, ptr->content) > 0)
			{
				content = cur->content;
				content_size = cur->content_size;
				cur->content = ptr->content;
				cur->content_size = ptr->content_size;
				ptr->content = content;
				ptr->content_size = content_size;
			}
			ptr = ptr->next;
		}
		cur = cur->next;
	}
}
