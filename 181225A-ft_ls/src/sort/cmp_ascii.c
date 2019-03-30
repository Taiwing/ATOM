/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_ascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:55:38 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/19 07:56:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsfdata.h"

int		strcmp_file_names(void *f1, void *f2)
{
	return (ft_strcmp(((t_lsfdata *)f1)->name, ((t_lsfdata *)f2)->name));
}

int		strcmp_file_names_rev(void *f1, void *f2)
{
	return (ft_strcmp(((t_lsfdata *)f2)->name, ((t_lsfdata *)f1)->name));
}
