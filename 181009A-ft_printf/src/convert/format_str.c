/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:43:42 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/02 20:16:57 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_str.h"

static void	apply_precision(t_fstr *s, t_params *conv)
{
	s->zero_pad = conv->precision - s->l_str - (s->str[0] == '-');
	if (s->str[0] == '-')
	{
		s->sign = '-';
		s->str[0] = '0';
	}
	s->l_total += s->zero_pad;
}

static void	apply_hash(t_fstr *s, t_params *conv)
{
	if (conv->type == 'o' && !s->zero_pad && s->str[0] != '0')
	{
		s->zero_pad++;
		s->l_total++;
	}
	else (conv->type == 'x' || conv->type == 'X')
	{
		s->hex = conv->type == 'x' ? "0x" : "0X";
		s->l_total += 2;
	}
}

static void	apply_fw(t_fstr *s, t_params *conv)
{
	int	l;

	if (conv->type && s->l_total < conv->fw)
	{
		s->space_pad = (conv->fw - s->total) * (conv->flags & F_ZERO ? 1 : -1);
		s->l_total = conv->fw;
	}
}

void		format_str(t_fstr *s, t_params *conv)
{
	char	t;

	t = conv->type;
	s->l_str = conv->type == 'c' ? 1 : ft_strlen(s->str);
	s->l_total = s->l_str;
	if (t == 'd' || t == 'u' || t == 'o' || t == 'x' || t == 'X')
	{
		if (conv->precision > s->l_total - (s->str[0] == '-'))
			apply_precision(s, conv);
		if (t != 'd' && conv->flags & F_HASH)
			apply_hash(s, conv);
		if (t == 'd' && s->str[0] != '-'
			&& (conv->flags & F_PLUS || conv->flags & F_SPACE))
		{
			s->sign = conv->flags & F_PLUS ? '+' : ' ';		
			s->l_total++;
		}
		if (s->l_total < conv->fw && conv->flags & F_ZERO
			&& !(conv->flags & F_MINUS))
		{
			s->zero_pad += conv->fw - s->l_total;
			s->l_total = conv->fw;
		}
	}
	apply_fw(s, conv);
}
