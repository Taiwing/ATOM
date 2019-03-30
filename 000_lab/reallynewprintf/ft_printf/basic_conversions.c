/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:36:04 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/18 20:02:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "fetch.h"
#include "libft.h"
#include "itoa_unsigned.h"

void	c_conversion(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	int				l;
	unsigned char	nb;

	if (!conv->arg)
		fetch(cur, 0, C_CHAR | C_UNSIGNED, (void *)(&nb));
	else
		fetch(ref, conv->arg, C_CHAR | C_UNSIGNED, (void *)(&nb));
	l = nb < 0x80 ? 1 : 2;
	add_to_buf(loc, NULL, 0, l);
	if (loc->n == 1)
		loc->buf[0] = (char)nb;
	else if (loc->n == 2)
	{
		loc->buf[0] = 0xc0 | (nb >> 6);
		loc->buf[1] = 0x80 | (nb & 0x3f);
	}
}

void	s_conversion(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	char	*str;

	if (!conv->arg)
		fetch(cur, 0, C_CHAR_P, (void *)(&str));
	else
		fetch(ref, conv->arg, C_CHAR_P, (void *)(&str));
	if (!str && (conv->prec > 5 || conv->prec < 0))
		add_to_buf(loc, "(null)", 0, 6);
	else if (str && (conv->prec < 0 || ft_memchr((void *)str, 0, conv->prec)))
		add_to_buf(loc, str, 0, ft_strlen(str));
	else if (str)
		add_to_buf(loc, str, 0, conv->prec);
}

void	p_conversion(t_pdata *loc, va_list cur, va_list ref, t_params *conv)
{
	unsigned long int	ptr;

	if (!conv->arg)
		fetch(cur, 0, C_INT | C_LONG | C_UNSIGNED, (void *)(&ptr));
	else
		fetch(ref, conv->arg, C_INT | C_LONG | C_UNSIGNED, (void *)(&ptr));
	if (!ptr)
	{
		add_to_buf(loc, "(nil)", 0, 5);
		conv->type = 's';
	}
	else
		itoa_ulint(loc, ptr, 16, conv->type == 'P');
}
