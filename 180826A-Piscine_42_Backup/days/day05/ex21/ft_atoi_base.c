/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:40:07 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/06 18:59:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_nbr_valid(char *str, char *base, int *l)
{
	char	*ptr;

	*l = 0;
	while (*l >= 0 && str[*l])
	{
		ptr = base;
		while (*ptr && !(str[*l] == *ptr || (str[*l] == 43 && *l == 0)
				|| (str[*l] == 45 && *l == 0)))
			ptr++;
		if (!*ptr && *l > 0)
			return (1);
		*l = *ptr ? *l + 1 : -1;
	}
	return (*l > 0);
}

int	is_base_valid(char *base, int *b)
{
	char	*ptr;

	*b = 0;
	while (*b >= 0 && base[*b])
	{
		ptr = base;
		while (*ptr && (*ptr != base[*b] || ptr == &base[*b])
				&& *ptr != 43 && *ptr != 45)
			ptr++;
		*b = *ptr ? -1 : *b + 1;
	}
	return (*b > 1);
}

int	powaaa(int a, int b)
{
	return (b ? a * powaaa(a, b - 1) : 1);
}

int	conversion(char *str, int l, char *base, int b)
{
	int d;
	int	p;
	int	nbr;

	p = l - 1;
	nbr = 0;
	while (p + 1 && str[p] > 47 && str[p] < 58)
	{
		d = 0;
		while (str[p] != base[d] && str[p] != 43 && str[p] != 45)
			d++;
		if (str[p] == 43 || str[p] == 45)
			nbr *= str[p] == 45 ? -1 : 1;
		else
			nbr += d * powaaa(b, l - p - 1);
		p--;
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int b;
	int l;

	if (is_base_valid(base, &b) && is_nbr_valid(str, base, &l))
		return (conversion(str, l, base, b));
	else
		return (0);
}
