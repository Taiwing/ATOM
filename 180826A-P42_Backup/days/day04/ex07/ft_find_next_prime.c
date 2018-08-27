/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 02:56:01 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/05 14:13:55 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	if (ft_is_prime(nb))
		return (nb);
	else if (nb <= 1)
		return (2);
	i = (nb % 2 == 0) ? nb + 1 : nb + 2;
	while (1)
	{
		if (ft_is_prime(i))
			return (i);
		i += 2;
	}
}
