/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:54:02 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/31 16:08:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_conv.h"

void	get_conv(char **fmt, va_list cur, va_list ref, t_params *conv)
{
	char	*eof;

	(*fmt)++;
	conv->soc = *fmt;
	conv->eoc = get_type(*fmt, conv);
	eof = *(conv->eoc) ? get_cast(conv->eoc, conv) : NULL;
	if (check_type_cast(conv) && conv->soc <= eof && conv->type != '%')
	{
		if (!get_flags(eof, cur, ref, conv))
		{
			conv->soc = conv->soc - 1;
			conv->type = 0;
		}
	}
	*fmt = conv->eoc + 1;
}
