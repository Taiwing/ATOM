/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 06:30:42 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/18 09:21:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*ptr;

	if (!begin_list || !data || !cmp)
		return ;
	new = ft_create_elem(data);
	ptr = *begin_list;
	if (!ptr || (*cmp)(new->data, ptr->data) < 0)
	{
		*begin_list = new;
		new->next = ptr;
	}
	else
	{
		while (ptr->next && (*cmp)(new->data, ptr->next->data) > 0)
			ptr = ptr->next;
		new->next = ptr->next;
		ptr->next = new;
	}
}
