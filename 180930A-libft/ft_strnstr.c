/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:53:33 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:53:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		l;
	const char	*needle;

	l = ft_strlen(to_find);
	while (*str && *to_find)
	{
		needle = to_find;
		while (*str && *needle && *str == *needle && l <= n)
		{
			str++;
			needle++;
		}
		if (*needle == 0)
			return ((char *)str - l);
		str -= needle - to_find;
		if (*str++ == 0 || --n < l)
			return (0);
	}
	return (l ? 0 : (char *)str);
}
