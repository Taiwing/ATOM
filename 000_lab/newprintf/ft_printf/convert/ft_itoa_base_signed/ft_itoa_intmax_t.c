/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:00:48 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 08:00:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa_cast.h"

char	*ft_itoa_intmax_t(intmax_t n)
{
	static int	l = 0;
	char		*str;
	char		c;

	l++;
	if (l == 1)
		c = n < 0 ? 45 : (n % 10) + 48;
	else
		c = n < 0 ? ((n % -10) * -1) + 48 : (n % 10) + 48;
	if ((n / 10 || n % 10) && n < 0 && l == 1)
		str = ft_itoa_intmax_t(n);
	else if (n / 10)
		str = ft_itoa_intmax_t(n < 0 ? n / -10 : n / 10);
	else
	{
		str = (char *)malloc(l + 1);
		str[l] = 0;
	}
	str[--l] = c;
	if (l == 0)
		ft_strrev(str[0] == 45 ? str + 1 : str);
	return (str);
}
