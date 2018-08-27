/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:00:11 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:00:13 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_strcmp(char *s1, char *s2)
{
	return (*s1 && *s2 && *s1 == *s2 ? ft_strcmp(s1 + 1, s2 + 1) : *s1 - *s2);
}

int		ft_atoi(char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 12))
		str++;
	if (*str == 43 || *str == 45)
		sign = *str++ == 45 ? -1 : sign;
	while (*str > 47 && *str < 58)
		nb = (nb * 10) + (*str++ - 48);
	return (nb * sign);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
