/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:01:01 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/05 18:47:22 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	while (*str)
	{
		if (*str > 31 && *str < 127)
			ft_putchar(*str++);
		else
		{
			ft_putchar('\\');
			ft_putchar(hexa[*str / 16]);
			ft_putchar(hexa[*str % 16]);
			str++;
		}
	}
}
