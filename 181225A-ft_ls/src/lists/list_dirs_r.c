/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:28:44 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 18:27:32 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"
#include "lsfdata.h"
#include "libft.h"
#include "list_files.h"
#include "ls_sort.h"
#include "ls_print.h"
#include "ft_ls_errors.h"
#include "list_dirs.h"

static void	print_file_list_r(t_lsconfig *cfg, t_lsddata *lsd)
{
	t_lsfdata	*lsf;
	t_list		*cur;
	t_list		*last_dir;

	last_dir = NULL;
	cur = lsd->ls_files;
	while (cur)
	{
		lsf = (t_lsfdata *)cur->content;
		cfg->ls_print_file(lsf, cfg);
		if (!lsf->isdir)
		{
			if (cur == lsd->ls_files)
				lsd->ls_files = cur->next;
			ft_lst_move_to_front(last_dir, &cur, &cfg->ls_bank);
		}
		else
		{
			last_dir = cur;
			cur = cur->next;
		}
	}
	lsd->ls_files = !last_dir ? NULL : lsd->ls_files;
	flush_pbuf(&cfg->buf);
}

void		list_dir_r(t_lsconfig *cfg, const char *path, const char *dirname)
{
	int			len;
	t_lsddata	lsd;

	len = 0;
	lsd.path = build_path(path, dirname);
	ls_print_dir(cfg, lsd.path);
	if (!(lsd.dirp = opendir(lsd.path)))
	{
		put_opendir_error(lsd.path, cfg);
		free(heap_collector(lsd.path, HS_GET));
		return ;
	}
	dir_heap_collector(lsd.dirp, HS_ADD);
	cfg->list_files(cfg, &lsd, &len);
	print_errors(cfg);
	if (cfg->sortf)
		cfg->sortf(lsd.ls_files, cfg, len);
	print_file_list_r(cfg, &lsd);
	cfg->dir_recurse(cfg, &lsd);
	free(heap_collector(lsd.path, HS_GET));
	closedir((DIR *)dir_heap_collector(lsd.dirp, HS_GET));
}

void		list_first_dir_r(t_lsconfig *cfg)
{
	int			len;
	t_lsddata	lsd;

	len = 0;
	lsd.path = cfg->args_len ? cfg->args[0] : ".";
	if (!(lsd.dirp = opendir(lsd.path)))
	{
		put_opendir_error(lsd.path, cfg);
		return ;
	}
	dir_heap_collector(lsd.dirp, HS_ADD);
	cfg->list_files(cfg, &lsd, &len);
	print_errors(cfg);
	if (cfg->sortf)
		cfg->sortf(lsd.ls_files, cfg, len);
	print_file_list_r(cfg, &lsd);
	cfg->dir_recurse(cfg, &lsd);
	closedir((DIR *)dir_heap_collector(lsd.dirp, HS_GET));
}

void		dir_recursion_hide_on(t_lsconfig *cfg, t_lsddata *lsd)
{
	t_list		*lst;

	lst = lsd->ls_files;
	while (lst)
	{
		if (cfg->new_line)
			add_to_pbuf(&cfg->buf, NULL, '\n', 1);
		list_dir_r(cfg, lsd->path, ((t_lsfdata *)lst->content)->name);
		ft_lst_move_to_front(NULL, &lst, &cfg->ls_bank);
	}
}

/*if a or f is on, then recursion must skip "." and ".."*/
void		dir_recursion_hide_off(t_lsconfig *cfg, t_lsddata *lsd)
{
	t_list		*lst;

	lst = lsd->ls_files;
	while (lst)
	{
		if (ft_strcmp(((t_lsfdata *)lst->content)->name, ".")
			&& ft_strcmp(((t_lsfdata *)lst->content)->name, ".."))
		{
			if (cfg->new_line)
				add_to_pbuf(&cfg->buf, NULL, '\n', 1);
			list_dir_r(cfg, lsd->path, ((t_lsfdata *)lst->content)->name);
		}
		ft_lst_move_to_front(NULL, &lst, &cfg->ls_bank);
	}
}
