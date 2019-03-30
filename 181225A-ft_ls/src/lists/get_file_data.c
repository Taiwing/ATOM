/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:12:52 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 16:12:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_long_data.h"
#include "ft_ls_errors.h"

int	get_file_data_one(char *path, t_lsfdata *lsf,
		t_lsconfig *cfg, struct dirent *fp)
{
	(void)path;
	(void)cfg;
	if (fp)
		lsf->isdir = (fp->d_type == DT_DIR);
	return (0);
}

int	get_file_data_columns(char *path, t_lsfdata *lsf,
		t_lsconfig *cfg, struct dirent *fp)
{
	int	l;

	(void)path;
	if (fp)
		lsf->isdir = (fp->d_type == DT_DIR);
	++(cfg->lsp.list_len);
	l = ft_strlen(lsf->name);
	if (cfg->lsp.name_max < l)
		cfg->lsp.name_max = l;
	return (0);
}

int	get_file_data_long(char *path, t_lsfdata *lsf,
		t_lsconfig *cfg, struct dirent *fp)
{
	if (lstat(path, &lsf->stats))
	{
		add_error(path, cfg);
		return (-1);
	}
	lsf->isdir = fp ? (fp->d_type == DT_DIR) :
				((lsf->stats.st_mode & S_IFMT) == S_IFDIR);
	cfg->lsp.total += lsf->stats.st_blocks;
	get_long_data(path, lsf, cfg);
	return (0);
}
