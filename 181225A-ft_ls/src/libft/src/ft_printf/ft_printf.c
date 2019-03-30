/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:43:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:46:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

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
	print_buf(&data, 1);
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf(&data);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser(&data, (char **)&format, &args);
	print_buf(&data, fd);
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf_str(&data, str, 0);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser_str(&data, (char **)&format, &args);
	if (data.n != -1)
		str[data.n] = 0;
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

int	ft_snprintf(char *str, int size, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	if (!size)
		return (0);
	init_buf_str(&data, str, size);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1 && data.n < size - 1)
		parser_str(&data, (char **)&format, &args);
	if (data.n != -1)
		str[data.n] = 0;
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

int	ft_asprintf(char **str, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf_alloc(&data, str);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser_alloc(&data, (char **)&format, &args);
	if (data.n != -1)
	{
		*str = data.buf;
		(*str)[data.n] = 0;
	}
	else
		free(heap_collector(data.buf, HS_GET));
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}
