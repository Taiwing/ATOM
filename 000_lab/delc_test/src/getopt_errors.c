/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 05:59:39 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/11 09:18:48 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "getopt_utils.h"
#include <stdlib.h>
#include <unistd.h>

void	getopt_puterr(const char *str)
{
	write(2, str, ft_strlen(str));
}

void	option_puterr(const char *prefix, const char *name)
{
	getopt_puterr(" '");
	getopt_puterr(prefix);
	getopt_puterr(name);
	getopt_puterr("'");
}

void	print_short_error(int missing, char *prog_name, char c)
{
	getopt_puterr(prog_name);
	getopt_puterr(missing ? ": option requires an argument -- "
					: ": illegal option -- ");
	write(2, &c, 1);
	getopt_puterr("\n");
}
