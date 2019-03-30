/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:25 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 11:57:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dirs.h"
#include "lsfdata.h"
#include "ls_sort.h"
#include "ft_ls_errors.h"
#include <stdlib.h>

static void	list_arg_dirs(t_lsconfig *cfg, t_list *arg_files)
{
	while (arg_files)
	{
		if (cfg->new_line)
			add_to_pbuf(&cfg->buf, NULL, '\n', 1);
		cfg->ls_dir(cfg, NULL, ((t_lsfdata *)arg_files->content)->name);
		ft_lst_move_to_front(NULL, &arg_files, &cfg->ls_bank);
	}
}

static void	print_arg_files(t_lsconfig *cfg, t_list **arg_files)
{
	t_lsfdata	*lsf;
	t_list		*cur;
	t_list		*last_dir;

	last_dir = NULL;
	cur = *arg_files;
	while (cur)
	{
		lsf = (t_lsfdata *)cur->content;
		if ((lsf->stats.st_mode & S_IFMT) != S_IFDIR)
		{
			cfg->ls_print_file(lsf, cfg);
			if (cur == *arg_files)
				*arg_files = cur->next;
			ft_lst_move_to_front(last_dir, &cur, &cfg->ls_bank);
		}
		else
		{
			last_dir = cur;
			cur = cur->next;
		}
	}
	flush_pbuf(&cfg->buf);
}

static void	list_arg_files(t_lsconfig *cfg, t_list **arg_files, int *len)
{
	t_lsfdata	lsf_buf;

	*len = 0;	
	while (*cfg->args)
	{
		ft_strcpy(lsf_buf.name, *cfg->args);
		if (!cfg->get_arg_data(lsf_buf.name, &lsf_buf, cfg))
		{
			ft_lst_push_back(arg_files, (void *)&lsf_buf, sizeof(t_lsfdata));
			++(*len);
		}
		++cfg->args;
	}
}

static void	list_args(t_lsconfig *cfg)
{
	int			len;
	t_list		*arg_files;

	cfg->lsp = (t_lsprint) {-1, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0};
	arg_files = NULL;
	list_arg_files(cfg, &arg_files, &len);
	if (cfg->args_len == 1 && arg_files
		&& (((t_lsfdata *)arg_files->content)->stats.st_mode & S_IFMT)
		== S_IFDIR)
	{
		--cfg->args;
		cfg->ls_first_dir(cfg);
		ft_lst_move_to_front(NULL, &arg_files, &cfg->ls_bank);
	}
	else
	{
		print_errors(cfg);
		if (arg_files && cfg->sortf)
			cfg->sortf(arg_files, cfg, len);
		print_arg_files(cfg, &arg_files);
		list_arg_dirs(cfg, arg_files);
	}
}

void		get_args(t_lsconfig *cfg)
{
	if (!cfg->args_len)
		cfg->ls_first_dir(cfg);
	else
		list_args(cfg);
}
