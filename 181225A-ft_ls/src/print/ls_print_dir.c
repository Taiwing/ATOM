/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:41:42 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:00:40 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"

void	ls_print_dir(t_lsconfig *cfg, char *dirname)
{
	ft_bufprintf(&cfg->buf, "%s:\n", dirname);
	cfg->new_line = 1;
}
