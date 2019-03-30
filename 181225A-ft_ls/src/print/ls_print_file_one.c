/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_file_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:33:42 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:09:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"

void	ls_print_file_one(t_lsfdata *lsf, t_lsconfig *cfg)
{
	ft_bufprintf(&cfg->buf, "%s\n", lsf->name);
	cfg->new_line = 1;
}
