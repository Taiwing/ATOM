/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 06:32:12 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/18 09:25:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	insert(t_list **begin_list, t_list *new, int (*cmp)())
{
	t_list	*ptr;

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*ptr;

	if (!begin_list1)
		return ;
	ptr = begin_list2;
	while (ptr)
	{
		begin_list2 = begin_list2->next;
		insert(begin_list1, ptr, cmp);
		ptr = begin_list2;
	}
}
