/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:44:21 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/23 06:24:02 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dirs.h"
#include "lsfdata.h"
#include "ls_sort.h" 
#include "ft_ls_errors.h"

static void	print_arg_files_d(t_lsconfig *cfg, t_list **arg_files)
{
	t_lsfdata	*lsf;

	while (*arg_files)
	{
		lsf = (t_lsfdata *)(*arg_files)->content;
		cfg->ls_print_file(lsf, cfg);
		ft_lst_move_to_front(NULL, arg_files, &cfg->ls_bank);
	}
	flush_pbuf(&cfg->buf);
}

static void	list_args_d(t_lsconfig *cfg, int *len)
{
	t_list		*arg_files;
	t_lsfdata	lsf_buf;

	*len = 0;
	arg_files = NULL;
	while (*cfg->args)
	{
		ft_strcpy(lsf_buf.name, *cfg->args);
		if (!cfg->get_file_data(lsf_buf.name, &lsf_buf, cfg, NULL))
		{
			ft_lst_push_back(&arg_files, (void *)&lsf_buf, sizeof(t_lsfdata));
			++(*len);
		}
		++cfg->args;
	}
	print_errors(cfg);
	if (arg_files && cfg->sortf)
		cfg->sortf(arg_files, cfg, *len);
	print_arg_files_d(cfg, &arg_files);
}

void		get_args_d(t_lsconfig *cfg)
{
	int			len;
	t_lsfdata	lsf;

	cfg->lsp = (t_lsprint) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0};
	if (!cfg->args_len)
	{
		ft_strcpy(lsf.name, ".");
		if (!cfg->get_file_data(lsf.name, &lsf, cfg, NULL))
			cfg->ls_print_file(&lsf, cfg);
		else
			print_errors(cfg);
	}
	else
		list_args_d(cfg, &len);
}
