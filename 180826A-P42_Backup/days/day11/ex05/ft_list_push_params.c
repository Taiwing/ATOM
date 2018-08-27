/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:38:59 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 09:58:06 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!av || !*av)
		return (0);
	new_list = ft_create_elem((void *)av[--ac]);
	new_elem = new_list;
	while (ac--)
	{
		new_elem->next = ft_create_elem((void *)av[ac]);
		new_elem = new_elem->next;
	}
	return (new_list);
}
