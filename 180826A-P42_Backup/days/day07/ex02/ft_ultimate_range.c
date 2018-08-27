/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:06:19 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/08 17:06:23 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	nb;
	int	size;

	size = max - min;
	if (size > 0)
	{
		*range = (int *)malloc(size * sizeof(int));
		nb = min - 1;
		while (++nb < max)
			(*range)[nb - min] = nb;
	}
	else
		*range = NULL;
	return (size < 0 ? 0 : size);
}
