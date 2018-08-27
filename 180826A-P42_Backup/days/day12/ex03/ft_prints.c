/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:04:59 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:13:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prints.h"

void	ft_print_byte(int byte, int ascii, int last)
{
	int	p;

	p = ascii ? 8 : 7;
	while (byte < ft_pow(16, --p) && p > 0)
		ft_putchar('0');
	ft_putnbr_base(byte, "0123456789abcdef");
	if (!last)
		ft_putchar(' ');
	if (ascii && !last)
		ft_putchar(' ');
}

void	ft_print_hex(char *ptr, int l)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < l)
		{
			if (ptr[i] < 16)
				ft_putchar('0');
			ft_putnbr_base(ptr[i], "0123456789abcdef");
		}
		else
			ft_putstr("  ");
		if (i == 7)
			ft_putchar(' ');
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_hex2(char *ptr, int l)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < l)
		{
			if (ptr[i] < 16)
				ft_putchar('0');
			ft_putnbr_base(ptr[i], "0123456789abcdef");
		}
		else
			ft_putstr("  ");
		if (i < 15)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_char(char *ptr, int l)
{
	ft_putstr(" |");
	while (l--)
	{
		ft_putchar(*ptr > 31 && *ptr < 127 ? *ptr : '.');
		ptr++;
	}
	ft_putstr("|\n");
}
