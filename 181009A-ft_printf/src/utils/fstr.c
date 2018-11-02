/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:57:24 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/02 19:16:57 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fstr.h"

t_fstr	*initfstr(void)
{
	t_fstr	*s;

	s = (t_fstr *)malloc(sizeof(t_fstr));
	s->space_pad = 0;
	s->hex = NULL;
	s->sign = 0;
	s->zero_pad = 0;
	s->l_total = 0;
	s->l_str = 0;
	return (s);
}

void	putfstr(t_fstr *s)
{
	while (s->space_pad > 0)
	{
		write(1, " ", 1);
		s->space_pad--;
	}
	if (s->hex)
		write(1, s->hex, 2);
	if (s->sign)
		write(1, &(s->sign), 1);
	while (s->zero_pad > 0)
	{
		write(1, "0", 1);
		s->zero_pad--;
	}
	if (s->l_str && s->str)
		write(1, s->str, s->l_str);
	while (s->space_pad < 0)
	{
		write(1, " ", 1);
		s->space_pad++;
	}
}

void	delfstr(t_fstr **s)
{
	if (*s && (*s)->str)
		free((*s)->str);
	if (*s)
		free(*s);
	*s = NULL;
}
