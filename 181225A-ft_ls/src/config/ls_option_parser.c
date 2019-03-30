/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_option_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:41:58 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 17:44:04 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ls_options.h"
#include "ft_getopt.h"
#include "list_files.h"
#include "list_dirs.h"
#include "list_dirs_r.h"
#include "get_args.h"
#include "get_args_d.h"
#include "ls_sort.h"
#include "get_file_data.h"
#include "get_arg_data.h"
#include "ls_print.h"
#include "get_mode_time.h"
#include "get_xa.h"

static void	set_print_function(t_lsconfig *cfg)
{
	if (cfg->printmode == P_COLUMNS && !isatty(1))
		cfg->printmode = P_ONE;
	if (cfg->printmode == P_ONE)
		cfg->ls_print_file = ls_print_file_one;
	else if (cfg->printmode == P_LONG)
	{
		if (!cfg->fieldmode)
			cfg->ls_print_file = ls_print_file_long;
		else if ((cfg->fieldmode & F_GROUP) && !(cfg->fieldmode & F_OWNER))
			cfg->ls_print_file = ls_print_file_long_g;
		else if (!(cfg->fieldmode & F_GROUP) && (cfg->fieldmode & F_OWNER))
			cfg->ls_print_file = ls_print_file_long_o;
		else
			cfg->ls_print_file = ls_print_file_long_go;
	   	cfg->get_time = cfg->timemode == T_MODIF ?
			get_time_modif : cfg->get_time;
	   	cfg->get_time = cfg->timemode == T_ACCESS ?
			get_time_access : cfg->get_time;
	   	cfg->get_time = cfg->timemode == T_CREATION ?
			get_time_creation : cfg->get_time;
	}
}

static void	set_sort_time(t_lsconfig *cfg)
{
	cfg->sortf = sort_size_or_time;
	if (cfg->reverse)
	{
	   	cfg->cmp = cfg->timemode == T_MODIF ?
			cmp_file_modif_rev : cfg->cmp;
	   	cfg->cmp = cfg->timemode == T_ACCESS ?
			cmp_file_access_rev : cfg->cmp;
	   	cfg->cmp = cfg->timemode == T_CREATION ?
			cmp_file_creation_rev : cfg->cmp;
	}
	else
	{
	   	cfg->cmp = cfg->timemode == T_MODIF ?
			cmp_file_modif : cfg->cmp;
	   	cfg->cmp = cfg->timemode == T_ACCESS ?
			cmp_file_access : cfg->cmp;
	   	cfg->cmp = cfg->timemode == T_CREATION ?
			cmp_file_creation : cfg->cmp;
	}
}

static void	set_sort_functions(t_lsconfig *cfg)
{
	if (!cfg->sortmode)				/*no sort (option f is set)*/
		cfg->sortf = NULL;
	else if (cfg->sortmode != S_ASCII || cfg->reverse)
	{
		if (cfg->sortmode == S_ASCII)
			cfg->cmp = strcmp_file_names_rev;
		else if (cfg->sortmode == S_SIZE)
		{
			cfg->sortf = sort_size_or_time;
			cfg->cmp = cfg->reverse ? cmp_file_sizes_rev : cmp_file_sizes;
		}
		else if (cfg->sortmode == S_TIME)
			set_sort_time(cfg);
		cfg->cmp2 = cfg->reverse ? strcmp_file_names_rev : cfg->cmp2;
	}
}

static void	set_lists_functions(t_lsconfig *cfg)
{
	cfg->get_arguments = cfg->dirmode == D_AS_FILE ? get_args_d : get_args;
	if (cfg->printmode == P_ONE)
	{
		cfg->get_file_data = get_file_data_one;
		cfg->get_arg_data = get_arg_data_one;
	}
	else if (cfg->printmode == P_LONG)
	{
		cfg->get_file_data = get_file_data_long;
		cfg->get_arg_data = get_arg_data_long;
		cfg->get_xa = get_xattracl;
	}
	if (cfg->dirmode == D_RECURSIVE)
	{
		cfg->ls_first_dir = list_first_dir_r;
		cfg->ls_dir = list_dir_r;
	}
	if (!cfg->hide)	/*hide off (option a or f is set)*/
	{
		cfg->list_files = list_files_hide_off;
		cfg->dir_recurse = dir_recursion_hide_off;
	}
}

void		ls_option_parser(t_lsconfig *cfg, int argc, char **argv)
{
	int				c;
	struct winsize	w;
	t_optdata		od;

	init_getopt(&od, OPTSTRING, 0, 0);
	while ((c = ft_getopt(argc, argv, &od)) != -1)
		g_set_opt[c](cfg);
	cfg->args = argv + od.optind;
	cfg->args_len = argc - od.optind;
	set_lists_functions(cfg);
	set_sort_functions(cfg);
	set_print_function(cfg);
	if (cfg->printmode == P_LONG)
	{
		if (cfg->show_ext && cfg->show_acl)
			cfg->get_xa = get_all_xattracl;
		else if (cfg->show_ext)
			cfg->get_xa = get_xattr_only;
		else if (cfg->show_acl)
			cfg->get_xa = get_acl_only;
	}
	if (cfg->printmode == P_COLUMNS && !(cfg->term_width =
		ioctl(0, TIOCGSIZE, &w) != -1 ? w.ws_col : 0))
		cfg->printmode = P_ONE;
}
