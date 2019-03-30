/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:32:21 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/17 16:28:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_flags.h"
#include "fetch.h"
#include "libft.h"

static int	doll_sign(char *f)
{
	char	*ref;

	ref = f;
	while (*f > 47 && *f < 58)
		f++;
	return (ref != f && *f == '$');
}

static int	add_flag(char c, t_params *conv)
{
	if (c == '#')
		conv->flags |= F_HASH;
	else if (c == '0')
		conv->flags |= F_ZERO;
	else if (c == '-')
		conv->flags |= F_MINUS;
	else if (c == ' ')
		conv->flags |= F_SPACE;
	else if (c == '+')
		conv->flags |= F_PLUS;
	else
		return (0);
	return (1);
}

static int	star_sign(char **f, int *ptr, va_list cur, va_list ref)
{
	int	nb;
	int	value;

	nb = -1;
	if (**f == '*')
	{
		if (doll_sign(++(*f)))
		{
			if (!(nb = ft_atoi_forward(f)))
				return (-1);
			fetch(ref, nb, C_INT, (void *)&value);
			(*f)++;
		}
		else
			fetch(cur, 0, C_INT, (void *)&value);
		*ptr = value;
	}
	else if (**f > 47 && **f < 58)
		*ptr = ft_atoi_forward(f);
	else
		return (0);
	return (1);
}

int			get_flags(char **fmt, va_list cur, va_list ref, t_params *conv)
{
	int		i;

	if (doll_sign(*fmt))
	{
		if (!(conv->arg = ft_atoi_forward(fmt)))
			return (0);
		(*fmt)++;
	}
	while (add_flag(**fmt, conv))
		(*fmt)++;
	if (star_sign(fmt, &(conv->fw), cur, ref) < 0)
		return (0);
	conv->flags |= conv->fw < 0 ? F_MINUS : 0;
	conv->fw *= conv->fw < 0 ? -1 : 1;
	if (**fmt == '.')
	{
		(*fmt)++;
		if ((i = star_sign(fmt, &(conv->prec), cur, ref)) < 0)
			return (0);
		else if (i == 0)
			conv->prec = 0;
	}
	return (1);
}
