/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:19:51 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/06 18:45:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		is_base_valid(char *base, int *b)
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

void	print_nb(int nbr, char *base, int b)
{
	if (nbr < 0)
		ft_putchar('-');
	if (nbr / b)
		print_nb(nbr < 0 ? nbr / -b : nbr / b, base, b);
	ft_putchar(base[nbr < 0 ? (nbr % -b) * -1 : nbr % b]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int b;

	if (is_base_valid(base, &b))
		print_nb(nbr, base, b);
}
