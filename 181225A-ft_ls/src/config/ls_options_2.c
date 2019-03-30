/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:27:16 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/26 16:13:23 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"

void	set_e(t_lsconfig *cfg)
{
	cfg->show_acl = 1;
}

void	set_f(t_lsconfig *cfg)
{
	cfg->sortmode = S_NO_SORT;
	cfg->hide = 0;
	cfg->reverse = 0;
}

void	set_g(t_lsconfig *cfg)
{
	cfg->printmode = P_LONG;
	cfg->fieldmode |= F_GROUP;
}

void	set_l(t_lsconfig *cfg)
{
	cfg->printmode = P_LONG;
}

void	set_o(t_lsconfig *cfg)
{
	cfg->printmode = P_LONG;
	cfg->fieldmode |= F_OWNER;
}
