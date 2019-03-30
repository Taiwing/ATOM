/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:13:54 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 11:55:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_options.h"

void	usage(t_lsconfig *cfg)
{
	(void)cfg;
	ft_putstr_fd("usage: ls [-" OPTSTRING "] [file ...]\n", 2);
	frexit();
}
