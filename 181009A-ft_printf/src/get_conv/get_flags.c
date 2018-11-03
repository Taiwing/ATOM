/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:32:21 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/03 16:56:07 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_flags.h"

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

static int	star_sign(char **f, long int *ptr, va_list cur, va_list ref)
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
			fetch(ref, nb, T_INT, (void *)&value);
			(*f)++;
		}
		else
			fetch(cur, 0, T_INT, (void *)&value);
		*ptr = (long int)value;
	}
	else if (**f > 47 && **f < 58)
		*ptr = (long int)ft_atoi_forward(f);
	else
		return (0);
	return (1);
}

int			get_flags(char *eof, va_list cur, va_list ref, t_params *conv)
{
	int		i;
	char	*f;

	f = conv->soc;
	if (doll_sign(f))
	{
		if (!(conv->arg = ft_atoi_forward(&f)))
			return (0);
		f++;
	}
	while (add_flag(*f, conv))
		f++;
	if (star_sign(&f, &(conv->fw), cur, ref) < 0)
		return (0);
	conv->flags |= conv->fw < 0 ? F_MINUS : 0;
	conv->fw *= conv->fw < 0 ? -1 : 1;
	if (*f == '.')
	{
		f++;
		if ((i = star_sign(&f, &(conv->precision), cur, ref)) < 0)
			return (0);
		else if (i == 0)
			conv->precision = 0;
	}
	return (f == eof + 1);
}
