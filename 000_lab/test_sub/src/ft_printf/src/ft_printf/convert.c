/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:10:27 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/19 23:49:36 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conversions.h"
#include "format_data.h"
#include "libft.h"

void	convert(t_pdata *data, t_farg *args, t_params *conv, char **fmt)
{
	t_pdata	loc_data;

	init_buf(&loc_data);
	if (ft_strchr("dbBouxX", conv->type))
		itoa_cast(&loc_data, args, conv);
	else if (ft_strchr("eEfFgG", conv->type))
		efg_conversions(&loc_data, args, conv);
	else if (conv->type == 'p' || conv->type == 'P')
		p_conversion(&loc_data, args, conv);
	else if (conv->type == 'c')
		c_conversion(&loc_data, args, conv);
	else if (conv->type == 'C')
		lc_conversion(&loc_data, args, conv);
	else if (conv->type == 's')
		s_conversion(&loc_data, args, conv);
	else if (conv->type == 'S')
		ls_conversion(&loc_data, args, conv);
	else if (conv->type == 't')
		t_conversion(&loc_data, args, conv, fmt);
	else
		add_to_buf(&loc_data, NULL, conv->type, 1);
	if (loc_data.n != -1)
		format_data(data, &loc_data, conv, 0);
	data->n = loc_data.n == -1 ? -1 : data->n;
	free(loc_data.abuf);
}
