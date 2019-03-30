/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_file_long_g.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:55:43 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:04:57 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_mode_time.h"
#include "ls_print_xa.h"

static void	print_long_dev_g(t_lsfdata *lsf, t_lsconfig *cfg,
							char *mode, char *time)
{
	int	maj;
	int	min;
	int	off_set;

	maj = (lsf->stats.st_rdev & 0xff000000) >> 24;
	min = lsf->stats.st_rdev & 0xff;
	off_set = cfg->lsp.bytes_field > 8 ? cfg->lsp.bytes_field - 8 : 0;
	ft_bufprintf(&cfg->buf, "%-11s %*ld %-*s %*d, %3d %12s %s\n", mode,
	cfg->lsp.links_field, lsf->stats.st_nlink, cfg->lsp.group_field, lsf->group,
	off_set + 3 + 1, maj, min, time, lsf->name);
}

static void	print_long_reg_g(t_lsfdata *lsf, t_lsconfig *cfg,
							char *mode, char *time)
{
	ft_bufprintf(&cfg->buf, "%-11s %*ld %-*s %*lld %12s %s\n", mode,
	cfg->lsp.links_field, lsf->stats.st_nlink, cfg->lsp.group_field, lsf->group,
	cfg->lsp.bytes_field + 1, lsf->stats.st_size, time, lsf->name);
}

static void	print_long_link_g(t_lsfdata *lsf, t_lsconfig *cfg,
							char *mode, char *time)
{
	ft_bufprintf(&cfg->buf, "%-11s %*ld %-*s %*lld %12s %s -> %s\n", mode,
	cfg->lsp.links_field, lsf->stats.st_nlink, cfg->lsp.group_field, lsf->group,
	cfg->lsp.bytes_field + 1, lsf->stats.st_size, time,
	lsf->name, lsf->link_target);
	free(heap_collector(lsf->link_target, HS_GET));
}

void		ls_print_file_long_g(t_lsfdata *lsf, t_lsconfig *cfg)
{
	char	mode_str[16];
	char	time_str[13];

	get_mode_str(mode_str, lsf->stats.st_mode, lsf->xattr_acl);
	cfg->get_time(time_str, lsf);
	if (cfg->lsp.total != -1 && cfg->lsp.list_len != -1 && cfg->dirmode)
	{
		ft_bufprintf(&cfg->buf, "total %d\n", cfg->lsp.total);
		cfg->lsp.total = -1;
	}
	if (mode_str[0] == 'l')
		print_long_link_g(lsf, cfg, mode_str, time_str);
	else if (mode_str[0] == 'c' || mode_str[0] == 'b')
		print_long_dev_g(lsf, cfg, mode_str, time_str);
	else
		print_long_reg_g(lsf, cfg, mode_str, time_str);
	if (lsf->ls_attr_acl)
		print_xa(&lsf->ls_attr_acl, cfg);
	free(heap_collector(lsf->user, HS_GET));
	free(heap_collector(lsf->group, HS_GET));
	cfg->new_line = 1;
}
