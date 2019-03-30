/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:26:50 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/24 15:15:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"

void	set_up_r(t_lsconfig *cfg)
{
	cfg->dirmode = cfg->dirmode ? D_RECURSIVE : 0;
}

void	set_up_s(t_lsconfig *cfg)
{
	cfg->sortmode = cfg->sortmode ? S_SIZE : 0;
}

void	set_up_u(t_lsconfig *cfg)
{
	cfg->timemode = T_CREATION;
}

void	set_a(t_lsconfig *cfg)
{
	cfg->hide = 0;
}

void	set_d(t_lsconfig *cfg)
{
	cfg->dirmode = D_AS_FILE;
}
