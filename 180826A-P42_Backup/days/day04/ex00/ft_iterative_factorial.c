/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 02:33:28 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/03 02:37:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int fact;

	if (nb < 0 || nb > 12)
		return (0);
	else
	{
		fact = 1;
		while (nb)
			fact *= nb--;
		return (fact);
	}
}
