/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:27:23 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/26 16:19:16 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_options.h"

void	set_r(t_lsconfig *cfg)
{
	cfg->reverse = (cfg->sortmode != 0);
}

void	set_t(t_lsconfig *cfg)
{
	if (cfg->sortmode && cfg->sortmode != S_SIZE)
		cfg->sortmode = S_TIME;
}

void	set_u(t_lsconfig *cfg)
{
	cfg->timemode = T_ACCESS;
}

void	set_1(t_lsconfig *cfg)
{
	cfg->printmode = P_ONE;
}

void	set_at(t_lsconfig *cfg)
{
	cfg->show_ext = 1;
}
