/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 05:46:13 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 11:28:09 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	static t_list	*prev = 0;
	t_list			*next;
	t_list			*cur;

	if (!begin_list || !*begin_list || !data_ref || !cmp)
		return ;
	cur = *begin_list;
	next = cur->next;
	if ((*cmp)(data_ref, cur->data) == 0)
	{
		free(cur);
		cur = 0;
		if (prev)
			prev->next = next;
		else
			*begin_list = next;
	}
	prev = cur ? cur : prev;
	if (next)
		ft_list_remove_if(&next, data_ref, cmp);
	else
		prev = 0;
}
