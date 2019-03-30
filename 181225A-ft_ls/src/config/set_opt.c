/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:24:26 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/26 15:54:23 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_options.h"

void	(* const g_set_opt[256])(t_lsconfig *cfg) = {
	['R'] = set_up_r,
	['S'] = set_up_s,
	['U'] = set_up_u,
	['a'] = set_a,
	['d'] = set_d,
	['e'] = set_e,
	['f'] = set_f,
	['g'] = set_g,
	['l'] = set_l,
	['o'] = set_o,
	['r'] = set_r,
	['t'] = set_t,
	['u'] = set_u,
	['1'] = set_1,
	['@'] = set_at,
	['?'] = usage
};
