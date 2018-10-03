#include "libft.h"

void	ft_putelemstr(t_list *lst)
{
	ft_putstr((char *)(lst->content));
	ft_putchar(lst->next == NULL ? '\n' : ' ');
}

t_list	*ft_romone(t_list *elem)
{
	char	*str[2];
	t_list	*new = NULL;

	if (elem->content_size)
	{
		str[0] = (char *)elem->content;
		str[1] = ft_strnew(elem->content_size);
		for (size_t i = 0; i < elem->content_size-1; i++)
			str[1][i] = str[0][i]+1;
		new = ft_lstnew((void *)str[1], elem->content_size);
	}

	return new;
}

void	ft_delelem(void *content, size_t content_size)
{
	if (content_size)
		free(content);
}

int		main(void)
{
	t_list	*lst = ft_lstnew(ft_strdup("list."), 6);
	t_list	*romlst = NULL;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
			case 0:
				ft_lstadd(&lst, ft_lstnew((void *)ft_strdup("a"), 2));
				break;
			case 1:
				ft_lstadd(&lst, ft_lstnew((void *)ft_strdup("am"), 3));
				break;
			case 2:
				ft_lstadd(&lst, ft_lstnew((void *)ft_strdup("I"), 2));
				break;
			case 3:
				ft_lstadd(&lst, ft_lstnew((void *)ft_strdup("Hello,"), 7));
				break;
		}
	}
	ft_lstiter(lst, ft_putelemstr);
	romlst = ft_lstmap(lst, ft_romone);
	ft_lstiter(romlst, ft_putelemstr);
	ft_lstdel(&lst, ft_delelem);
}
