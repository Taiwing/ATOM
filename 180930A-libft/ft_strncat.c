/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:52:25 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:52:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*d;

	if (!dest || !src)
		return (NULL);
	d = ft_strchr(dest, 0);
	while (n-- && *src)
		*d++ = *src++;
	*d = 0;
	return (dest);
}
