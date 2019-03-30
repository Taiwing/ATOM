/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:34:46 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/18 17:42:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_conv.h"
#include "get_flags.h"
#include "libft.h"

static int	get_type(char **fmt, t_params *conv)
{
	char	*t;

	if (!(t = ft_strchr("dDioOuUxXcCsSpP%", **fmt)))
		return (0);
	if (*t == 'D' || *t == 'O' || *t == 'U')
	{
		//TODO: calibrate this line for abnormal use
		conv->cast |= *t == 'D' ? C_LONG : C_LONG | C_UNSIGNED;
		conv->type = *t + 32;	
	}
	else if (*t == 'u' || *t == 'o' || *t == 'x' || *t == 'X')
	{
		conv->cast |= C_UNSIGNED;
		conv->type = *t;
	}
	else if (*t == 'c' && conv->cast & C_LONG)
		conv->type = 'C';
	else
		conv->type = *t == 'i' ? 'd' : *t;
	(*fmt)++;
	return (1);
}

static int	get_cast(char **fmt, t_params *conv)
{
	int	c;

	c = 0;
	while (**fmt == 'h' || **fmt == 'l' || **fmt == 'j' || **fmt == 'z')
	{
		if (**fmt == 'h' && !(conv->cast & C_SHORT))
			conv->cast |= C_SHORT;
		else if (**fmt == 'h')
			conv->cast = (conv->cast | C_CHAR) & ~C_SHORT;
		else if (**fmt == 'l' && !(conv->cast & C_LONG))
			conv->cast |= C_LONG;
		else if (**fmt == 'l')
			conv->cast = (conv->cast | C_LONG_LONG) & ~C_LONG;
		else if (**fmt == 'j')
			conv->cast |= C_INTMAX_T;
		else if (**fmt == 'z')
			conv->cast |= C_SIZE_T;
		c += **fmt == 'j' || **fmt == 'z' ? 2 : 1;
		if (c > 2)// || (conv->cast & (C_SHORT | C_LONG)))
			return (0);
		(*fmt)++;
	}
	return (1);
}

int			get_conv(char **fmt, va_list cur, va_list ref, t_params *conv)
{
	(*fmt)++;
	if (!get_flags(fmt, cur, ref, conv) || !get_cast(fmt, conv)
		|| !get_type(fmt, conv))
		return (0);
	return (1);
}
