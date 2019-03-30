/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:37:18 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 11:58:02 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"
#include <sys/syslimits.h>	/*for the PATH_MAX macro*/
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/xattr.h>

static char	*get_link_target(char *path)
{
	ssize_t	len;
	char	buf[PATH_MAX];

	len = readlink(path, buf, PATH_MAX);
	return (ft_strndup(buf, len));
}

static void	get_bytes_field(t_lsfdata *lsf, t_lsconfig *cfg)
{
	if ((lsf->stats.st_mode & S_IFMT) == S_IFBLK ||
		(lsf->stats.st_mode & S_IFMT) == S_IFCHR)
	{
		if (cfg->lsp.bytes_max < 10000000)
		{
			cfg->lsp.bytes_max = 10000000;
			cfg->lsp.bytes_field = 8;
		}
	}
	if (lsf->stats.st_size > cfg->lsp.bytes_max)
	{
		cfg->lsp.bytes_max = lsf->stats.st_size;
		cfg->lsp.bytes_field = ft_intlen(lsf->stats.st_size);
	}
}

static void	get_usrgrp(t_lsfdata *lsf, long int uid, long int gid)
{
	struct passwd	*u;
	struct group	*g;

	if (!(u = getpwuid(uid)) || !(lsf->user = u->pw_name))
		ft_asprintf(&lsf->user, "%ld", uid);
	else
		lsf->user = ft_strdup(lsf->user);
	if (!(g = getgrgid(gid)) || !(lsf->group = g->gr_name))
		ft_asprintf(&lsf->group, "%ld", gid);
	else
		lsf->group = ft_strdup(lsf->group);
}

void		get_long_data(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	int		l;

	cfg->get_xa(path, lsf, cfg);
	if (lsf->stats.st_nlink > cfg->lsp.links_max)
	{
		cfg->lsp.links_max = lsf->stats.st_nlink;
		cfg->lsp.links_field = ft_intlen(lsf->stats.st_nlink);
	}
	get_bytes_field(lsf, cfg);
	get_usrgrp(lsf, lsf->stats.st_uid, lsf->stats.st_gid);
	l = ft_strlen(lsf->user);
	if (l > cfg->lsp.user_field)
		cfg->lsp.user_field = l;
	l = ft_strlen(lsf->group);
	if (l > cfg->lsp.group_field)
		cfg->lsp.group_field = l;
	if ((lsf->stats.st_mode & S_IFMT) == S_IFLNK)
		lsf->link_target = get_link_target(path);
}
