/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:46:08 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:46:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;

	m = (unsigned char *)s;
	while (*m != (unsigned char)c && n)
	{
		n--;
		m++;
	}
	return (n ? (void *)m : NULL);
}
