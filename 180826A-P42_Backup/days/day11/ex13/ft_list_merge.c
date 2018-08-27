/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 07:18:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 06:18:12 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*lst;

	if (!begin_list1)
		return ;
	lst = *begin_list1;
	while (lst && lst->next)
		lst = lst->next;
	if (lst)
		lst->next = begin_list2;
	else
		*begin_list1 = begin_list2;
}
