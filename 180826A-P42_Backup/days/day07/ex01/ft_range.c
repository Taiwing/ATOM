/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 00:45:49 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/10 00:48:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = -1;
	if (min >= max)
		return (NULL);
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (++i < max - min)
		tab[i] = min + i;
	return (tab);
}
