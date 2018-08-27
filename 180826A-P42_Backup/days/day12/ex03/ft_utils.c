/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:04:07 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:12:30 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int		ft_pow(int a, int b)
{
	return (b ? a * ft_pow(a, b - 1) : 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr < 0)
		ft_putchar(45);
	if (nbr / 16)
		ft_putnbr_base(nbr < 0 ? nbr / -16 : nbr / 16, base);
	ft_putchar(base[nbr < 0 ? (nbr % 16) * -1 : nbr % 16]);
}
