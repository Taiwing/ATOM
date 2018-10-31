/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:53:39 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/29 21:33:30 by yforeau          ###   ########.fr       */
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
		s->len = perc ? perc - *fmt : ft_strlen(*fmt);
		s->str = ft_strsub(*fmt, 0, s->len);
		(*fmt) += s->len;
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
