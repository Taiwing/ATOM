/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 08:16:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/12 08:19:52 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_op.h"
#include "utils.h"

t_op	g_optab[] =
{
	{"+", &add},
	{"-", &sub},
	{"*", &mul},
	{"/", &div},
	{"%", &mod}
};

t_op_func	get_op(char *opstr)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (ft_strcmp(opstr, g_optab[i].symb) == 0)
			return (g_optab[i].f);
	}
	return (0);
}
