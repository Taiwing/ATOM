/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 22:16:43 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/14 20:42:21 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_formats.h"
#include "utils.h"
#include "t_params.h"

void	e_format(t_pdata *loc, char *buf, int size, t_fltinf *info)
{
	add_to_buf(loc, buf, 0, 1);
	if (info->prec)
	{
		add_to_buf(loc, NULL, '.', 1);
		add_to_buf(loc, buf + 1, 0,
				size - 1 > info->prec ? info->prec : size - 1);
		if ((size - 1) < info->prec)
			add_to_buf(loc, NULL, '0', info->prec - (size - 1));
	}
	else if (info->flags & F_HASH)
		add_to_buf(loc, NULL, '.', 1);
	add_to_buf(loc, 0, info->conv, 1);
	add_to_buf(loc, 0, info->exp10 < 0 ? '-' : '+', 1);
	if (info->exp10 > -10 && info->exp10 < 10)
		add_to_buf(loc, 0, '0', 1);
	info->exp10 *= info->exp10 < 0 ? -1 : 1;
	size = uitoa_buf((unsigned int)info->exp10, 10, 0, buf);
	add_to_buf(loc, buf, 0, size);
}

void	f_format(t_pdata *loc, char *buf, int size, t_fltinf *info)
{
	if (info->exp10 < 0)
	{
		add_to_buf(loc, "0.", 0, 2);
		add_to_buf(loc, NULL, '0', -(info->exp10 + 1));
		add_to_buf(loc, buf, 0, size);
		if ((info->prec - size + info->exp10 + 1) > 0)
			add_to_buf(loc, NULL, '0', info->prec - size + info->exp10 + 1);
	}
	else
	{
		add_to_buf(loc, buf, 0, info->exp10 + 1);
		if (info->prec)
		{
			add_to_buf(loc, NULL, '.', 1);
			add_to_buf(loc, buf + info->exp10 + 1, 0, size - info->exp10 - 1);
			add_to_buf(loc, NULL, '0', info->prec - (size - info->exp10 - 1));
		}
		else if (info->flags & F_HASH)
			add_to_buf(loc, NULL, '.', 1);
	}
}

void	g_format(t_pdata *loc, char *buf, int size, t_fltinf *info)
{
	if (!(info->flags & F_HASH))
	{
		while (size > 1 && buf[size - 1] == '0')
			--size;
	}
	else
	{
		while (size < info->prec + 1)
			buf[size++] = '0';
	}
	if (info->exp10 < -4 || info->exp10 > info->prec)
	{
		info->conv -= 2;
		info->prec = size - 1;
		e_format(loc, buf, size, info);
	}
	else
	{
		info->prec = info->exp10 < 0 ? size : size - info->exp10 - 1;
		f_format(loc, buf, size, info);
	}
}
