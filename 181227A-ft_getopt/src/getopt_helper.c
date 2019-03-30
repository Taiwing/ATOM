/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 07:49:24 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/09 07:49:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

void	init_varopts(t_varopts *vars, t_opt *longopts,
						int *longindex, unsigned int *historic)
{
	vars->optind = 1;
	vars->optopt = 0;
	vars->optarg = 0;
	vars->historic = historic;
	vars->longopts = longopts;
	vars->longindex = longindex;
}
