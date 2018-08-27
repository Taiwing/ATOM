/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 07:45:36 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/14 11:42:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	t_list	*ptr;
	void	*data;

	cur = *begin_list;
	while (cur && cur->next)
	{
		ptr = cur->next;
		while (ptr)
		{
			if ((*cmp)(cur->data, ptr->data) > 0)
			{
				data = cur->data;
				cur->data = ptr->data;
				ptr->data = data;
			}
			ptr = ptr->next;
		}
		cur = cur->next;
	}
}
