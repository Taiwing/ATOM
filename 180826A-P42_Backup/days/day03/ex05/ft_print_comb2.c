/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_print_comb2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 04:50:19 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/02 17:40:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

static void	ft_printlr(int l, int r)
{
	ft_putchar(48 + (l / 10));
	ft_putchar(48 + (l % 10));
	ft_putchar(32);
	ft_putchar(48 + (r / 10));
	ft_putchar(48 + (r % 10));
	if (l < 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void		ft_print_comb2(void)
{
	int l;
	int r;

	l = 0;
	r = 0;
	while (l < 99)
	{
		r = l + 1;
		while (r < 100)
		{
			ft_printlr(l, r);
			r++;
		}
		l++;
	}
}
