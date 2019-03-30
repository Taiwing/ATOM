/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:10:27 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/17 23:56:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "convert.h"
#include "conversions.h"
#include "format_data.h"

void	convert(t_pdata *data, va_list cur, va_list ref, t_params *conv)
{
	char	t;
	t_pdata	loc_data;	

	init_buf(&loc_data);
	t = conv->type;
	if (t == 'd' || t == 'u' || t == 'o' || t == 'x' || t == 'X')
		itoa_cast(&loc_data, cur, ref, conv);
	else if (t == 'p' || t == 'P')
		p_conversion(&loc_data, cur, ref, conv);
	else if (t == 'c')
		c_conversion(&loc_data, cur, ref, conv);
	else if (t == 'C')
		lc_conversion(&loc_data, cur, ref, conv);
	else if (t == 's')
		s_conversion(&loc_data, cur, ref, conv);
	else if (t == 'S')
		ls_conversion(&loc_data, cur, ref, conv);
	else if (t == '%')
		add_to_buf(&loc_data, "%", 0, 1);
	if (loc_data.n != -1)
		format_data(data, &loc_data, conv, 0);
	else
		data->n = -1;
	free(loc_data.abuf);
}
