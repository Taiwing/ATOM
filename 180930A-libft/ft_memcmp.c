/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:46:30 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:46:32 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	return (*(t_uchar *)s1 == *(t_uchar *)s2 ? ft_memcmp(s1 + 1, s2 + 1, n - 1)
		: *(t_uchar *)s1 - *(t_uchar *)s2);
}

