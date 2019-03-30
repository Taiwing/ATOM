/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:30:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 08:03:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lc_conversion.h"

static int	byte_len(wint_t c)
{
	int	l;

	l = 0;
	if (c < 0x80)
		l = 1;
	else if (c < 0x800)
		l = 2;
	else if (c < 0x10000)
		l = 3;
	else if (c < 0x200000)
		l = 4;
	return (l);
}

static void	conv_wint(char *str, int l, wint_t c)
{
	str[0] = l > 1 ? 0xf0 << (4 - l) : 0;
	while (--l > -1)
	{
		str[l] |= !l ? c : 0x80 | (c & 0x3f);
		c >>= 6;
	}
}

char		*lc_conversion(va_list cur, va_list ref, t_params *conv)
{
	int		l;
	wint_t	nb;
	char	*str;

	if (!conv->arg)
		fetch(cur, 0, T_WINT_T, (void *)(&nb));
	else
		fetch(ref, conv->arg, T_WINT_T, (void *)(&nb));
	l = byte_len(nb);
	str = ft_strnew(sizeof(char) * (l + 1));
	str[l] = 0;
	conv_wint(str, l, nb);
	return (str);
}
