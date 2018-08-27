/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 02:37:48 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/15 20:41:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*map;
	int	i;

	if (length < 1 || !(map = (int *)malloc(length * sizeof(int)))
		|| !tab || !f)
		return (0);
	i = -1;
	while (++i < length)
		map[i] = (*f)(tab[i]);
	return (map);
}
