/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:26:25 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/24 16:42:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsfdata.h"

int	cmp_file_modif(void *f1, void *f2)
{
	long int	m1;	
	long int	m2;

	m1 = ((t_lsfdata *)f1)->stats.st_mtime;
	m2 = ((t_lsfdata *)f2)->stats.st_mtime;
	if (m1 > m2)
		return (-1);
	else if (m1 < m2)
		return (1);
	else
		return (0);
}

int	cmp_file_modif_rev(void *f1, void *f2)
{
	long int	m1;	
	long int	m2;

	m1 = ((t_lsfdata *)f1)->stats.st_mtime;
	m2 = ((t_lsfdata *)f2)->stats.st_mtime;
	if (m1 < m2)
		return (-1);
	else if (m1 > m2)
		return (1);
	else
		return (0);
}
