/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:44:40 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/18 13:47:14 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itoa.h"
#include "fetch.h"
#include "itoa_signed.h"
#include "itoa_unsigned.h"

void	itoa_int(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	int				s;
	unsigned int	u;
	int				base;
	int				type;

	type = (conv->type == 'X' || conv->type == 'P');
	base = conv->type == 'o' ? 8 : 10;
	base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
	if (conv->cast & C_UNSIGNED)
		fetch(conv->arg ? ref : cur, conv->arg, C_INT | C_UNSIGNED, (void *)&u);
	else
		fetch(conv->arg ? ref : cur, conv->arg, C_INT, (void *)&s);
	if (conv->cast == (C_CHAR | C_UNSIGNED))
		itoa_uint(loc, (unsigned char)u, base, type);
	else if (conv->cast == (C_INT | C_SHORT | C_UNSIGNED))
		itoa_uint(loc, (unsigned short int)u, base, type);
	else if (conv->cast == (C_INT | C_UNSIGNED))
		itoa_uint(loc, u, base, type);
	else if (conv->cast & C_CHAR)
		itoa_sint(loc, (char)s);
	else if (conv->cast & C_SHORT)
		itoa_sint(loc, (short int)s);
	else if (conv->cast & C_INT)
		itoa_sint(loc, s);
}

void	itoa_long(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	long int			si;
	unsigned long int	ui;
	int					base;
	int					type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'o' ? 8 : 10;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&ui);
		itoa_ulint(loc, ui, base, type);
	}
	else
	{
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&si);
		itoa_slint(loc, si);
	}
}

void	itoa_long_long(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	long long int			si;
	unsigned long long int	ui;
	int						base;
	int						type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'o' ? 8 : 10;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&ui);
		itoa_ullint(loc, ui, base, type);
	}
	else
	{
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&si);
		itoa_sllint(loc, si);
	}
}

void	itoa_size_t(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	ssize_t	si;
	size_t	ui;
	int		base;
	int		type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'o' ? 8 : 10;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&ui);
		itoa_usize_t(loc, ui, base, type);
	}
	else
	{
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&si);
		itoa_ssize_t(loc, si);
	}
}

void	itoa_intmax_t(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	intmax_t	si;
	uintmax_t	ui;
	int			base;
	int			type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'o' ? 8 : 10;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&ui);
		itoa_uintmax_t(loc, ui, base, type);
	}
	else
	{
		fetch(conv->arg ? ref : cur, conv->arg, conv->cast, (void *)&si);
		itoa_sintmax_t(loc, si);
	}
}
