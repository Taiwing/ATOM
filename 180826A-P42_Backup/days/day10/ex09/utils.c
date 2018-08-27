/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 06:32:32 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/12 08:17:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar(45);
	if (n > 9 || n < -9)
		ft_putnbr(n < 0 ? n / -10 : n / 10);
	ft_putchar(n < 0 ? 48 + ((n % -10) * -1) : 48 + (n % 10));
}

int		ft_atoi(char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : sign;
	while (*str && *str > 47 && *str < 58)
		nb = (nb * 10) + ((*str++) - 48);
	return (nb * sign);
}

int		ft_strcmp(char *s1, char *s2)
{
	return (*s1 && *s2 && *s1 == *s2 ? ft_strcmp(s1 + 1, s2 + 1) : *s1 - *s2);
}
