/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:44:14 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:44:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
