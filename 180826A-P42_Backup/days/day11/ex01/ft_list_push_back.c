/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 02:39:13 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 06:19:12 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*ptr;

	if (!begin_list)
		return ;
	new = ft_create_elem(data);
	ptr = *begin_list;
	while (ptr && ptr->next)
		ptr = ptr->next;
	if (ptr)
		ptr->next = new;
	else
		*begin_list = new;
}
