/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:32:29 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/13 16:17:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putendl(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar(45);
	if (n > 9 || n < -9)
		ft_putnbr(n < 0 ? n / -10 : n / 10);
	ft_putchar(n < 0 ? 48 + ((n % -10) * -1) : 48 + (n % 10));
}

void	ft_show_tab(struct s_stock_par *par)
{
	int	i;

	while (par->str)
	{
		ft_putendl(par->str);
		ft_putnbr(par->size_param);
		ft_putchar('\n');
		i = 0;
		while (par->tab[i])
			ft_putendl(par->tab[i++]);
		par++;
	}
}
