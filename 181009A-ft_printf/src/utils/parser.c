/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:53:39 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/03 02:17:06 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_params	*init_conv(void)
{
	t_params	*conv;

	conv = (t_params *)malloc(sizeof(t_params));
	conv->type = 0;
	conv->cast = 0;
	conv->arg = 0;
	conv->flags = 0;
	conv->fw = 0;
	conv->precision = 0;
	conv->soc = NULL;
	conv->eoc = NULL;
	return (conv);
}

t_fstr		*parser(char **fmt, va_list cur, va_list ref)
{
	t_fstr		*s;
	char		*perc;
	t_params	*conv;

	s = initfstr();
	perc = ft_strchr(*fmt, '%');
	if (perc != *fmt)
	{
		s->l_str = perc ? perc - *fmt : (int)ft_strlen(*fmt);
		s->str = ft_strsub(*fmt, 0, s->l_str);
		s->l_total += s->l_str;
		(*fmt) += s->l_total;
	}
	else
	{
		conv = init_conv();
		get_conv(fmt, cur, ref, conv);
		convert(s, cur, ref, conv);
		free(conv);
	}
	return (s);
}
