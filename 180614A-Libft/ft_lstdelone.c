#include "libf4.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	(*del)((*alst)->content, (*alst)->content_size);
	(*alst)->next = NULL;
	ft_memdel((void **)alst);
}
