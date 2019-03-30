/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:34:35 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/17 16:57:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "get_conv.h"
#include "convert.h"

static void	init_conv(t_params *conv)
{
	conv->type = 0;
	conv->flags = 0;
	conv->cast = 0;
	conv->arg = 0;
	conv->fw = 0;
	conv->prec = -1;
}

void	parser(t_pdata *data, char **fmt, va_list cur, va_list ref)
{
	t_params	conv;
	char		*mod;

	mod = ft_strchr(*fmt, '%');
	if (mod  == *fmt)
	{
		init_conv(&conv);
		if (get_conv(fmt, cur, ref, &conv))
			convert(data, cur, ref, &conv);
	}
	else if (mod)
	{
		add_to_buf(data, *fmt, 0, mod - *fmt);
		*fmt = mod;
	}
	else
	{
		add_to_buf(data, *fmt, 0, ft_strlen(*fmt));
		*fmt = ft_strchr(*fmt, 0);
	}
}
