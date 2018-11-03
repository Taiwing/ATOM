/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:43:42 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/03 13:56:44 by yforeau          ###   ########.fr       */
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

static void	apply_hash(t_fstr *s, char t)
{
	if (t == 'o' && !s->zero_pad && s->str[0] != '0')
	{
		s->zero_pad++;
		s->l_total++;
	}
	else if (t == 'x' || t == 'X' || t == 'p' || t == 'P')
	{
		s->hex = t == 'x' || t == 'p' ? "0x" : "0X";
		s->l_total += 2;
	}
}

static void	apply_fw(t_fstr *s, t_params *conv, char t)
{
	if ((t == 'd' || t == 'u' || t == 'o' || t == 'x' || t == 'X' || t == 'p'
		|| t == 'P') && s->l_total < conv->fw && conv->flags & F_ZERO
		&& !(conv->flags & F_MINUS))
	{
		s->zero_pad += conv->fw - s->l_total - (s->str[0] == '-');
		s->l_total = conv->fw;
		if (s->str[0] == '-')
		{
			s->sign = '-';
			s->str[0] = '0';
		}
	}
	if (conv->type && s->l_total < conv->fw)
	{
		s->space_pad = conv->fw - s->l_total;
		s->space_pad *= conv->flags & F_MINUS ? -1 : 1;	
		s->l_total = conv->fw;
	}
}

void		format_str(t_fstr *s, t_params *conv)
{
	char	t;

	t = conv->type;
	s->l_str = conv->type == 'c' ? 1 : ft_strlen(s->str);
	s->l_total = s->l_str;
	if (t == 'd' || t == 'u' || t == 'o' || t == 'x' || t == 'X' 
		|| t == 'p' || t == 'P')
	{
		if (conv->precision > s->l_total - (s->str[0] == '-'))
			apply_precision(s, conv);
		if (t != 'd' && (conv->flags & F_HASH || t == 'p' || t == 'P'))
			apply_hash(s, t);
		if ((t == 'd' || t == 'p' || t == 'P') && s->str[0] != '-'
			&& (conv->flags & F_PLUS || conv->flags & F_SPACE))
		{
			s->sign = conv->flags & F_PLUS ? '+' : ' ';		
			s->l_total++;
		}
	}
	apply_fw(s, conv, t);
}
