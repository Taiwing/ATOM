/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:33:14 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/24 16:42:48 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsfdata.h"

int	cmp_file_creation(void *f1, void *f2)
{
	long int	m1;	
	long int	m2;

	m1 = ((t_lsfdata *)f1)->stats.st_birthtime;
	m2 = ((t_lsfdata *)f2)->stats.st_birthtime;
	if (m1 > m2)
		return (-1);
	else if (m1 < m2)
		return (1);
	else
		return (0);
}

int	cmp_file_creation_rev(void *f1, void *f2)
{
	long int	m1;	
	long int	m2;

	m1 = ((t_lsfdata *)f1)->stats.st_birthtime;
	m2 = ((t_lsfdata *)f2)->stats.st_birthtime;
	if (m1 < m2)
		return (-1);
	else if (m1 > m2)
		return (1);
	else
		return (0);
}
