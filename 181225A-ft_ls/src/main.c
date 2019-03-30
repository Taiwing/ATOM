/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:00:17 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/06 20:46:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_option_parser.h"
#include "get_args.h"

int	main(int argc, char **argv)
{
	t_lsconfig	cfg;

	init_lsconfig(&cfg);
	ls_option_parser(&cfg, argc, argv);
	cfg.get_arguments(&cfg);
	flush_pbuf(&cfg.buf);
	heap_collector(NULL, HS_FREE);
	return (cfg.ret);
}
