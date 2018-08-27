/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:44:07 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 06:30:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*ptr;
	void	*data;
	int		steps;
	int		length;

	length = 0;
	ptr = begin_list;
	while (ptr)
	{
		length++;
		ptr = ptr->next;
	}
	while (length > 1)
	{
		ptr = begin_list;
		steps = length;
		while (--steps)
			ptr = ptr->next;
		data = ptr->data;
		ptr->data = begin_list->data;
		begin_list->data = data;
		begin_list = begin_list->next;
		length -= 2;
	}
}
