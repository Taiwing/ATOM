/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:39:49 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 06:13:21 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	if (!begin_list || !*begin_list)
		return ;
	if (*begin_list && (*begin_list)->next)
		ft_list_clear(&((*begin_list)->next));
	free(*begin_list);
	*begin_list = 0;
}
