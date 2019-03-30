/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:43:15 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/17 16:26:32 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser.h"

int	ft_printf(const char *format, ...)
{
	t_pdata	data;
	va_list	cur;
	va_list	ref;

	init_buf(&data);
	va_start(cur, format);
	va_copy(ref, cur);
	while (*format && data.n != -1)
		parser(&data, (char **)&format, cur, ref);
	print_buf(&data);
	va_end(cur);
	va_end(ref);
	return (data.n);
}
