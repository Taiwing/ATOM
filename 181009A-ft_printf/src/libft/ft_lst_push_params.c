#include "libft.h"

t_list	*ft_lst_push_params(int ac, char **av)
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!av || !*av)
		return (0);
	new_list = ft_lstnew((void *)av[ac - 1], ft_strlen(av[ac + 1]) + 1);
	new_elem = new_list;
	while (--ac)
	{
		new_elem->next = ft_lstnew((void *)av[ac - 1], ft_strlen(av[ac + 1]) + 1);
		new_elem = new_elem->next;
	}
	return (new_list);
}
