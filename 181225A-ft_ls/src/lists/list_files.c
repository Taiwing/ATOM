/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:35:40 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/06 20:48:25 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"
#include "lsfdata.h"
#include "libft.h"

static void	init_list_data(t_lsprint *lsp, t_list ***lst,
							t_lsddata *lsd, char *path[2])
{
	*lsp = (t_lsprint) {0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0};
	lsd->ls_files = NULL;
	*lst = &lsd->ls_files;
	path[0] = ft_strnew(ft_strlen(lsd->path) + 256);
	ft_strcat(path[0], lsd->path);
	ft_strcat(path[0], "/");
	path[1] = ft_strchr(path[0], 0);
}

void	list_files_hide_off(t_lsconfig *cfg, t_lsddata *lsd, int *len)
{
	struct dirent	*fp;
	t_lsfdata		lsfb;
	t_lsfdata		*lsfp;
	t_list			**lst;
	char			*path[2];

	init_list_data(&cfg->lsp, &lst, lsd, path);
	while ((fp = readdir(lsd->dirp)))
	{
		lsfp = cfg->ls_bank ? (t_lsfdata *)cfg->ls_bank->content : &lsfb;
		ft_strcpy(path[1], ft_strcpy(lsfp->name, fp->d_name));
		if (!cfg->get_file_data(path[0], lsfp, cfg, fp))
		{
			if (lsfp == &lsfb)
				ft_lst_push_back(lst, (void *)lsfp, sizeof(t_lsfdata));
			else
				ft_lst_move_to_back(NULL, &cfg->ls_bank, lst);
			lst = &((*lst)->next);
			++(*len);
		}
	}
	free(heap_collector(path[0], HS_GET));
}

void	list_files_hide_on(t_lsconfig *cfg, t_lsddata *lsd, int *len)
{
	struct dirent	*fp;
	t_lsfdata		lsfb;
	t_lsfdata		*lsfp;
	t_list			**lst;
	char			*path[2];

	init_list_data(&cfg->lsp, &lst, lsd, path);
	while ((fp = readdir(lsd->dirp)))
	{
		if (fp->d_name[0] != '.')
		{
			lsfp = cfg->ls_bank ? (t_lsfdata *)cfg->ls_bank->content : &lsfb;
			ft_strcpy(path[1], ft_strcpy(lsfp->name, fp->d_name));
			if (!cfg->get_file_data(path[0], lsfp, cfg, fp))
			{
				if (lsfp == &lsfb)
					ft_lst_push_back(lst, (void *)lsfp, sizeof(t_lsfdata));
				else
					ft_lst_move_to_back(NULL, &cfg->ls_bank, lst);
				lst = &((*lst)->next);
				++(*len);
			}
		}
	}
	free(heap_collector(path[0], HS_GET));
}
