/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 08:16:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 01:13:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_op.h"
#include "utils.h"
#include "ft_opp.h"

int			ft_usage(int a, int b)
{
	int	i;

	(void)a;
	(void)b;
	ft_putstr("error : only [ ");
	i = -1;
	while (++i < 5)
	{
		ft_putstr(g_opptab[i].symb);
		ft_putstr(" ");
	}
	ft_putstr("] are accepted.\n");
	return (0);
}

t_op_func	get_op(char *opstr)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (ft_strcmp(opstr, g_opptab[i].symb) == 0)
			return (g_opptab[i].f);
	}
	return (g_opptab[i].f);
}
