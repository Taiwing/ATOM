/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:07:18 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/09 19:26:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_nbr(char *nbr, char *base, int b)
{
	int		d;
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	if (*nbr == '-' || *nbr == '+')
		sign = *nbr++ == '-' ? -1 : sign;
	while (*nbr)
	{
		d = 0;
		while (d < b && *nbr != base[d])
			d++;
		if (d == b)
			break ;
		nb = (nb * b) + d;
		nbr++;
	}
	return (nb * sign);
}

int		check_base(char *base)
{
	int		b;
	char	*ptr;

	b = 0;
	while (*base && b >= 0)
	{
		ptr = base + 1;
		while (*ptr && *ptr != 43 && *ptr != 45 && *ptr != *base)
			ptr++;
		b = *ptr ? -1 : b + 1;
		base++;
	}
	return (b);
}

char	*make_string(int nb, char *base, int b)
{
	int		i;
	int		j;
	char	*nbr;
	char	str[65];

	i = 0;
	if (nb < 0)
		str[i++] = '-';
	while (nb && b > 1)
	{
		str[i++] = nb < 0 ? base[(nb % -b) * -1] : base[nb % b];
		nb /= b;
	}
	if (i == 0)
		str[i++] = b > 1 ? base[0] : '0';
	nbr = (char *)malloc((i + 1) * sizeof(char));
	j = 0;
	if (str[0] == '-')
		nbr[j++] = str[0];
	while (str[0] == '-' ? i > 1 : i)
		nbr[j++] = str[--i];
	nbr[j] = 0;
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		b[2];

	b[0] = check_base(base_from);
	b[1] = check_base(base_to);
	nb = get_nbr(nbr, base_from, b[0]);
	return (make_string(nb, base_to, b[1]));
}
