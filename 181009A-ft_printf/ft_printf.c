/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:25:41 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/19 19:26:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		n;
	char	*fmt;
	t_fstr	*str;
	va_list	cur;
	va_list	ref;

	n = 0;
	fmt = format;
	va_start(cur, format);
	va_copy(ref, cur);
	while (*fmt)
	{
		str = parser(&fmt, cur, ref);
		putfstr(str);
		n += str->len;
		delfstr(&str);
	}
	va_end(cur);
	va_end(ref);
	return (n);
}
