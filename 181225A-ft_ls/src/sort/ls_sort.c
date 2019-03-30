/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:50:20 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/22 19:15:59 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"

static void	sort_equal_values(t_list *lst, t_lsconfig *cfg)
{
	int		len;
	t_list *cur;

	while (lst && lst->next)
	{
		if (!cfg->cmp(lst->content, lst->next->content))
		{
			len = 2;
			cur = lst->next;
			while (cur && cur->next &&
					!cfg->cmp(cur->content, cur->next->content))
			{	
				cur = cur->next;
				++len;
			}
			ft_lst_quicksort(lst, len, cfg->cmp2);
			lst = cur->next;
		}
		else
			lst = lst->next;
	}
}

void		sort_ascii(t_list *lst, t_lsconfig *cfg, int len)
{
	ft_lst_quicksort(lst, len, cfg->cmp);
}

void		sort_size_or_time(t_list *lst, t_lsconfig *cfg, int len)
{
	ft_lst_quicksort(lst, len, cfg->cmp);
	sort_equal_values(lst, cfg);
}
