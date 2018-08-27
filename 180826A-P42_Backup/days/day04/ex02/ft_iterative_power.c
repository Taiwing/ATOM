/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 02:40:55 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/03 02:41:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int iter;

	if (power < 0)
		return (0);
	else
	{
		iter = 1;
		while (power--)
			iter *= nb;
		return (iter);
	}
}
