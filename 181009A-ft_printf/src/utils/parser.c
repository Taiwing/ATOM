/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:53:39 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/02 20:22:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_fstr	*parser(char **fmt, va_list cur, va_list ref)
{
	t_fstr		*s;
	char		*perc;
	t_params	*conv;

	s = initfstr();
	perc = ft_strchr(*fmt, '%');
	if (perc != *fmt)
	{
		s->l_total = perc ? perc - *fmt : ft_strlen(*fmt);
		s->str = ft_strsub(*fmt, 0, s->l_total);
		(*fmt) += s->l_total;
	}
	else
	{
		conv = (t_params *)malloc(sizeof(t_params));
		get_conv(fmt, cur, ref, conv);
		convert(s, cur, ref, conv);
		free(conv);
	}
	return (s);
}
