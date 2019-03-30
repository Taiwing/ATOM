/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ulint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 07:57:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 07:57:48 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_cast.h"

char	*ft_itoa_base_ulint(t_ulint n, int base, int maj)
{
	int		i;
	int		size;
	int		nb[256];
	char	*str;

	if (base < 2 || base > 16)
		return (0);
	size = 0;
	while (n || !size)
	{
		nb[size++] = n % base;
		n /= base;
	}
	str = ft_strnew(size + 1);
	i = 0;
	while (size--)
		str[size] = g_bstr[maj][nb[i++]];
	return (str);
}
