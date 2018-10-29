/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:57:24 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/29 20:57:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fstr.h"

t_fstr	*initfstr(void)
{
	t_fstr	*s;

	s = (t_fstr *)malloc(sizeof(t_fstr));
	s->len = 0;
	s->str = NULL;
	return (s);
}

void	putfstr(t_fstr *s)
{
	if (s->len)
		write(1, s->str, s->len);
}

void	delfstr(t_fstr **s)
{
	if (*s && (*s)->str)
		free((*s)->str);
	if (*s)
		free(*s);
	*s = NULL;
}
