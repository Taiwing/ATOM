#include "libft.h"

t_list	*ft_lst_at(t_list *lst, unsigned int nbr)
{
	while (lst && nbr-- > 0)
		lst = lst->next;
	return (lst);
}
