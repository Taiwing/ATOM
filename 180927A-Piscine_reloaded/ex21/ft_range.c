/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:34:23 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:34:25 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;

	tab = min >= max ? NULL : (int *)malloc((max - min) * sizeof(int));
	while (tab && min < max--)
		tab[max - min] = max;
	return (tab);
}
