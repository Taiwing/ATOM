/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_discard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:21:10 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:16:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_discard(t_list *prev, t_list **alst)
{
	t_list	*next;

	if (!alst || !*alst)
		return ;
	next = (*alst)->next;
	free(heap_collector((*alst)->content, HS_GET));
	free(heap_collector(*alst, HS_GET));
	*alst = next;
	if (prev)
		prev->next = next;
}
