/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:52:59 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:53:02 by yforeau          ###   ########.fr       */
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
