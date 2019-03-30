/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:43:15 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/20 01:42:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

	init_buf(&data);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser(&data, (char **)&format, &args);
	if (data.n != -1)
	{
		ft_memcpy((void *)str, (void *)data.buf, data.n);
		str[data.n] = 0;
	}
	free(data.abuf);
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

int	ft_snprintf(char *str, int size, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf(&data);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser(&data, (char **)&format, &args);
	if (data.n != -1)
	{
		data.n = data.n > size - 1 ? size - 1 : data.n;
		ft_memcpy((void *)str, (void *)data.buf, data.n);
		str[data.n] = 0;
	}
	free(data.abuf);
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

int	ft_asprintf(char **str, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf(&data);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser(&data, (char **)&format, &args);
	if (data.n != -1)
	{
		if (!(*str = (char *)malloc(data.n + 1)))
			data.n = -1;
		else
		{
			ft_memcpy((void *)*str, (void *)data.buf, data.n);
			(*str)[data.n] = 0;
		}
	}
	free(data.abuf);
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}
