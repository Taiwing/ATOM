/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 23:06:54 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/13 16:21:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_par	*arr;

	arr = (t_stock_par *)malloc(++ac * sizeof(t_stock_par));
	while (--ac > -1)
	{
		arr[ac].str = av[ac];
		i = 0;
		while (av[ac] && av[ac][i])
			i++;
		arr[ac].size_param = i;
		arr[ac].copy = i ? (char *)malloc((i + 1) * sizeof(char)) : 0;
		j = -1;
		while (i && ++j < i + 1)
			arr[ac].copy[j] = arr[ac].str[j];
		arr[ac].tab = arr[ac].str ? ft_split_whitespaces(arr[ac].str) : 0;
	}
	return (arr);
}
