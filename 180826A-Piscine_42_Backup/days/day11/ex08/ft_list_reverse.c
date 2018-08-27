/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:53:17 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 10:09:48 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	static t_list	*prev = 0;
	t_list			*next;

	if (!begin_list || !*begin_list)
		return ;
	next = (*begin_list)->next;
	(*begin_list)->next = prev;
	prev = *begin_list;
	if (next)
		ft_list_reverse(&next);
	if (!(*begin_list)->next)
	{
		*begin_list = prev;
		prev = 0;
	}
}
