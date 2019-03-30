/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:19:13 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/07 13:20:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *d, const char *s, size_t n)
{
	char	*dest;

	if (!d || !s)
		return (NULL);
	dest = d;
	while (n && *s)
	{
		*d++ = *s++;
		n--;
	}
	ft_bzero(d, n);
	return (dest);
}
