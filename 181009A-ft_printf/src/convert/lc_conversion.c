/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:30:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/02 21:49:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lc_conversion.h"

char	*lc_conversion(va_list cur, va_list ref, t_params *conv)
{
	int		l;
	wint_t	nb;
	char	*str;

	if (!conv->arg)
		fetch(cur, 0, T_WINT_T, (void *)(&nb));
	else
		fetch(ref, conv->arg, T_WINT_T, (void *)(&nb));
	l = (nb && nb < 0x80);
	if (nb < 0x800)
		l = 2;
	else if (nb < 0x10000)
		l = 3;
	else if (nb < 0x200000)
		l = 4;
	str = (char *)malloc(sizeof(char) * (l + 1));
	str[l] = 0;
	str[0] = l > 1 ? 0xf0 << (4 - l) : 0;
	while (--l > -1)
	{
		str[l] |= !l ? nb : 0x80 | (nb & 0x3f);
		nb >>= 6;
	}
	return (str);
}

