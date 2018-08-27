/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 05:41:16 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 06:26:16 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !data_ref || !cmp)
		return (0);
	while (begin_list)
	{
		if ((*cmp)(data_ref, begin_list->data) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}
