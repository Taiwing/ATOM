/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:35:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/03 14:03:36 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lp_conversion.h"

char	*lp_conversion(va_list cur, va_list ref, t_params *conv)
{
	t_ulint	ptr;

	if (!conv->arg)
		fetch(cur, 0, T_INT | C_LONG | C_UNSIGNED, (void *)(&ptr));
	else
		fetch(ref, conv->arg, T_INT | C_LONG | C_UNSIGNED, (void *)(&ptr));
	if (!ptr)
	{
		conv->type = 's';
		return (ft_strdup("(nil)"));
	}
	return (ft_itoa_base_ulint(ptr, 16, 1));
}
