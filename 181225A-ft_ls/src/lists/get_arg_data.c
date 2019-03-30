/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:22:27 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 16:15:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_long_data.h"
#include "ft_ls_errors.h"

int	get_arg_data_one(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	if (stat(path, &lsf->stats))
	{
		add_error(path, cfg);
		return (-1);
	}
	return (0);
}

int	get_arg_data_columns(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	int	l;

	if (stat(path, &lsf->stats))
	{
		add_error(path, cfg);
		return (-1);
	}
	if ((lsf->stats.st_mode & S_IFMT) != S_IFDIR)
	{
		++(cfg->lsp.list_len);
		l = ft_strlen(lsf->name);
		if (cfg->lsp.name_max < l)
			cfg->lsp.name_max = l;
	}
	return (0);
}

int	get_arg_data_long(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	if (lstat(path, &lsf->stats))
	{
		add_error(path, cfg);
		return (-1);
	}
	if (!(lsf->isdir = (lsf->stats.st_mode & S_IFMT) == S_IFDIR))
		get_long_data(path, lsf, cfg);
	return (0);
}
