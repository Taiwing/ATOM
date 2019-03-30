/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_xa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 03:34:40 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:10:12 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"

void	print_xa(t_list **lst, t_lsconfig *cfg)
{
	while (*lst)
	{
		ft_bufprintf(&cfg->buf, "%s\n", (char *)((*lst)->content));
		ft_lst_discard(NULL, lst);
	}
}
