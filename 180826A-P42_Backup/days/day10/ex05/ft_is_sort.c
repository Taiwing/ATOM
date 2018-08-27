/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 03:37:17 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 00:09:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	if (!tab || !f)
		return (1);
	i = 0;
	while (i + 1 < length && (*f)(tab[i], tab[i + 1]) == 0)
		i++;
	if (i + 1 < length)
		order = (*f)(tab[i], tab[i + 1]);
	while (i + 1 < length)
	{
		if (order < 0 && (*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		else if (order > 0 && (*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}
