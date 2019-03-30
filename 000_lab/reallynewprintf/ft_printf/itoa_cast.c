/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:21:53 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/18 12:46:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "itoa.h"

void	itoa_cast(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	if (!(conv->cast >> 4))
		conv->cast |= C_INT;
	if (conv->cast == C_INT || conv->cast == (C_INT | C_UNSIGNED)
		|| conv->cast & C_CHAR || conv->cast & C_SHORT)
		itoa_int(loc, cur, ref, conv);
	else if (conv->cast & C_LONG)
		itoa_long(loc, cur, ref, conv);
	else if (conv->cast & C_LONG_LONG)
		itoa_long_long(loc, cur, ref, conv);
	else if (conv->cast & C_SIZE_T)
		itoa_size_t(loc, cur, ref, conv);
	else if (conv->cast & C_INTMAX_T)
		itoa_intmax_t(loc, cur, ref, conv);
}
