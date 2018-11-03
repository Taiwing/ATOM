/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:56:59 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/02 22:20:23 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

void	convert(t_fstr *s, va_list cur, va_list ref, t_params *conv)
{
	char	t;

	t = conv->type;
	if (t == 'd' || t == 'u' || t == 'o' || t == 'x' || t == 'X')
		s->str = ft_itoa_cast(cur, ref, conv);
	else if (t == 'c')
		s->str = c_conversion(cur, ref, conv);
	else if (t == 'C')
		s->str = lc_conversion(cur, ref, conv);
	else if (t == 's')
		s->str = s_conversion(cur, ref, conv);
	else if (t == 'S')
		s->str = ls_conversion(cur, ref, conv);
	else if (t == '%')
		s->str = ft_strdup("%");
	else if (!t)
		s->str = ft_strsub(conv->soc, 0, conv->eoc - conv->soc + 1);
	format_str(s, conv);
}
