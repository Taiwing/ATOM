/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:10:09 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/18 21:18:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_data.h"
#include "format_int_data.h"
#include "libft.h"

static void	apply_fw(t_pdata *l, t_params *conv, int fdat[4], int *size)
{
	char	*t;

	if ((t = ft_strchr("dbBouxXpPeEfFgG", conv->type)) && *size < conv->fw
		&& conv->flags & F_ZERO && !(conv->flags & F_MINUS)
		&& (conv->prec < 0 || ft_strchr("eEfFgG", conv->type)))
	{
		fdat[ZPAD] += conv->fw - *size - (l->buf[0] == '-');
		if (l->buf[0] == '-')
		{
			fdat[SIGN] = '-';
			l->buf[0] = '0';
		}
	}
	else if (!t && *size < conv->fw && conv->flags & F_ZERO
			&& !(conv->flags & F_MINUS) && conv->type != 't')
		fdat[ZPAD] = conv->fw - *size;
	else if (*size < conv->fw && conv->type != 't')
	{
		fdat[SPAD] = conv->fw - *size;
		fdat[SPAD] *= conv->flags & F_MINUS ? -1 : 1;
	}
	else
		return ;
	*size = conv->fw;
}

static void	apply_sign(t_pdata *l, t_params *conv, int fdat[4], int *size)
{
	if (ft_strchr("deEfFgG", conv->type) && l->buf[0] != '-'
		&& fdat[SIGN] != '-' && (conv->flags & F_PLUS || conv->flags & F_SPACE))
	{
		fdat[SIGN] = conv->flags & F_PLUS ? '+' : ' ';
		(*size)++;
	}
}

void		format_data(t_pdata *d, t_pdata *l, t_params *conv, int size)
{
	int		fdat[4];

	size = l->n;
	fdat[SPAD] = 0;
	fdat[ZPAD] = 0;
	fdat[SIGN] = 0;
	fdat[HEX] = 0;
	if (ft_strchr("dbBouxXpP", conv->type))
		int_format(conv, l, fdat, &size);
	apply_sign(l, conv, fdat, &size);
	apply_fw(l, conv, fdat, &size);
	if (fdat[SPAD] > 0)
		add_to_buf(d, NULL, ' ', fdat[SPAD]);
	if (fdat[SIGN])
		add_to_buf(d, NULL, fdat[SIGN], 1);
	if (fdat[HEX] && fdat[HEX] < 3)
		add_to_buf(d, fdat[HEX] == 1 ? "0x" : "0X", 0, 2);
	if (fdat[HEX] > 2)
		add_to_buf(d, fdat[HEX] == 3 ? "0b" : "0B", 0, 2);
	if (fdat[ZPAD] > 0)
		add_to_buf(d, NULL, '0', fdat[ZPAD]);
	add_to_buf(d, l->buf, 0, l->n);
	if (fdat[SPAD] < 0)
		add_to_buf(d, NULL, ' ', fdat[SPAD] * -1);
}
