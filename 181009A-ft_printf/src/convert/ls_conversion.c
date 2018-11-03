/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/03 12:24:03 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_conversion.h"

static int		byte_len(wchar_t c)
{
	int	l;

	l = 1;
	if (c > 0x7f)
		l = 2;
	else if (c > 0x7ff)
		l = 3;
	else if (c > 0xffff)
		l = 4;
	return (l);
}

static void		conv_wchar(char *str, int l, wchar_t c)
{
	str[0] = l > 1 ? 0xf0 << (4 - l) : 0;
	while (--l > -1)
	{
		str[l] |= !l ? c : 0x80 | (c & 0x3f);
		c >>= 6;
	}
}

static int		wstr_len(wchar_t *ws)
{
	int	l;

	l = 0;
	while (*ws++)
		l++;
	return (l);
}

char			*ls_conversion(va_list cur, va_list ref, t_params *conv)
{
	int			l;
	int			b;
	int			i;
	wchar_t		*wstr;
	char		*str;

	if (!conv->arg)
		fetch(cur, 0, T_WINT_T, (void *)(&wstr));
	else
		fetch(ref, conv->arg, T_WINT_T, (void *)(&wstr));
	if (!wstr)
		return (ft_strdup("(null)"));
	b = conv->precision;
	str = ft_strnew(b == -1 ? (wstr_len(wstr) * 4) + 1 : b + 1);
	i = 0;
	while (*wstr && (i < b || b == -1))
	{
		l = byte_len(*wstr);
		if (b == -1 || (i + l) <= b)
			conv_wchar(str + i, l, *wstr++);
		i += l;
	}
	return (str);
}

