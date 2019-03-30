/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atobint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:27:03 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/02 21:07:07 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint.h"

int		atobint(t_bint b, const char *s)
{
	bintclr(b);
	while (*s == 32 || (*s > 8 && *s < 14))
		s++;
	while (*s > 47 && *s < 58)
	{
		if (!smult10_bint(b) || !sadd_32bint(b, *s++ - 48))
			return (0);
	}
	return (1);
}
