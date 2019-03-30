/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:55:50 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/24 14:22:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsfdata.h"

int		cmp_file_sizes(void *f1, void *f2)
{
	long long int	s1;
	long long int	s2;

	s1 = ((t_lsfdata *)f1)->stats.st_size;
	s2 = ((t_lsfdata *)f2)->stats.st_size;
	if (s1 < s2)
		return (1);
	else if (s1 > s2)
		return (-1);
	else
		return (0);
}

int		cmp_file_sizes_rev(void *f1, void *f2)
{
	long long int	s1;
	long long int	s2;

	s1 = ((t_lsfdata *)f1)->stats.st_size;
	s2 = ((t_lsfdata *)f2)->stats.st_size;
	if (s1 > s2)
		return (1);
	else if (s1 < s2)
		return (-1);
	else
		return (0);
}
