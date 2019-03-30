/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:00:24 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/14 21:53:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_int_data.h"
#include "format_data.h"
#include "libft.h"

static void	apply_prec(t_pdata *l, t_params *conv, int *size, int fdat[4])
{
	fdat[ZPAD] = conv->prec - *size;
	if (l->buf[0] == '-')
	{
		fdat[SIGN] = '-';
		l->buf[0] = '0';
		(*size)++;
	}
	*size = *size + fdat[ZPAD];
}

static void	apply_hash(t_pdata *l, char t, int *size, int fdat[4])
{
	if (t == 'o' && !fdat[ZPAD] && (l->buf[0] != '0' || !l->n))
	{
		fdat[ZPAD]++;
		(*size)++;
	}
	else if ((ft_strchr("bBxX", t) && !(l->buf[0] == '0' && *size == 1)
			&& *size > 0) || t == 'p' || t == 'P')
	{
		*size = *size + 2;
		if (t == 'b' || t == 'B')
			fdat[HEX] = t == 'b' ? 3 : 4;
		else
			fdat[HEX] = t == 'x' || t == 'p' ? 1 : 2;
	}
}

void		int_format(t_params *conv, t_pdata *l, int fdat[4], int *size)
{
	if (conv->prec > *size - (l->buf[0] == '-'))
		apply_prec(l, conv, size, fdat);
	else if (!conv->prec && *size == 1 && l->buf[0] == '0')
	{
		(*size)--;
		(l->n)--;
		l->buf[0] = 0;
	}
	if (conv->type != 'd' && (conv->flags & F_HASH
		|| conv->type == 'p' || conv->type == 'P'))
		apply_hash(l, conv->type, size, fdat);
}
