/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 07:59:14 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 07:59:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_cast.h"

char	*ft_itoa_llint(t_llint n)
{
	int		i;
	int		size;
	int		sign;
	int		nb[256];
	char	*str;

	size = 0;
	sign = (n < 0);
	while (n || !size)
	{
		nb[size++] = sign ? (n % 10) * -1 : n % 10;
		n /= 10;
	}
	str = ft_strnew(size + 1 + sign);
	i = 0;
	while (size--)
		str[size + sign] = 48 + nb[i++];
	str[0] = sign ? '-' : str[0];
	return (str);
}
