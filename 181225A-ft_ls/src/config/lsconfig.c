/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsconfig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:20:07 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/26 16:11:00 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"
#include "list_dirs.h"
#include "list_dirs_r.h"
#include "list_files.h"
#include "ls_sort.h"
#include "ls_print.h"
#include "get_file_data.h"
#include "get_arg_data.h"

void	init_lsconfig(t_lsconfig *cfg)
{
	/*dfault values for options*/
	cfg->dirmode = D_DEFAULT;
	cfg->hide = 1;
	cfg->reverse = 0;
	cfg->sortmode = S_ASCII;
	cfg->timemode = T_MODIF;
	cfg->printmode = P_COLUMNS;
	cfg->fieldmode = 0;
	cfg->show_ext = 0;
	cfg->show_acl = 0;
	cfg->new_line = 0;
	cfg->ls_bank = NULL;
	cfg->ls_errors = NULL;
	cfg->ret = 0;
	/*default values for function pointers*/
	/*TODO: when implemented set get_file and get_arg default to columns*/
	cfg->get_file_data = get_file_data_columns;
	cfg->get_arg_data = get_arg_data_columns;
	cfg->ls_first_dir = list_first_dir;
	cfg->ls_dir = list_dir;
	cfg->list_files = list_files_hide_on;
	cfg->dir_recurse = dir_recursion_hide_on;
	cfg->sortf = sort_ascii;
	cfg->cmp = strcmp_file_names;
	cfg->cmp2 = strcmp_file_names;
	cfg->ls_print_file = ls_print_file_columns;
	init_pbuf(&cfg->buf, 1);
}
