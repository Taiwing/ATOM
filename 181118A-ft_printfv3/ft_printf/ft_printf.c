/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:43:15 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/25 15:26:45 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser.h"

int	ft_printf(const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf(&data);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser(&data, (char **)&format, &args);
	print_buf(&data);
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}
