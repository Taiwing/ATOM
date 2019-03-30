/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_file_columns.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:03:30 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 17:44:30 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"

static char	*alloc_buf(t_lsprint *p, t_pbuf *b)
{
	char	*buf;

	flush_pbuf(b);
	p->size = (p->line_c * (p->line_w + 1)) + 1;
	if (!b->n && p->size < PBUF_SIZE)
	{
		p->malloced = 0;
		ft_memset((void *)b->b, 0, p->size);
		return (b->b);
	}
	else
	{
		buf = (char *)ft_secmalloc(p->size);
		ft_memset((void *)buf, 0, p->size);
		p->malloced = 1;
		return (buf);
	}
}

static void	set_columns(t_lsconfig *cfg)
{
	t_lsprint		*p;
	int				grid_size;

	p = &cfg->lsp;
	p->col_w = p->name_max + 1;
	p->col_c = cfg->term_width / p->col_w;
	p->col_c = p->col_c > p->list_len ? p->list_len : p->col_c;
	p->col_c = p->col_c < 1 ? 1 : p->col_c;
	p->line_c = 1;
	while (p->line_c * p->col_c < p->list_len)
		++p->line_c;
	grid_size = p->col_c * p->line_c;
	while (p->col_c > 1 && (grid_size - p->list_len) > p->line_c)
	{
		--p->col_c;
		p->line_c = p->list_len / p->col_c;
		while ((grid_size = p->line_c * p->col_c) < p->list_len)
			++p->line_c;
	}
	p->line_w = p->col_c * p->col_w;
	p->buf = alloc_buf(p, &cfg->buf);
}

static void	print_and_destroy(t_lsconfig *cfg, t_lsprint *p)
{
	if (!p->malloced)
	{
		cfg->buf.n = cfg->buf.n ? cfg->buf.n : p->size;
		flush_pbuf(&cfg->buf);
	}
	else
		cfg->buf.n = write(cfg->buf.fd, p->buf, p->size) < 0 ? -1 : cfg->buf.n;
	cfg->new_line = 1;
	if (p->malloced)
		free(heap_collector(p->buf, HS_GET));
}

static int	bufferize(t_lsfdata *lsf, t_lsprint *p)
{
	int	i;

	i = (p->word_count * (p->line_w + 1)) + (p->col_count * p->col_w);
	/*if is the last word to be printed on a line*/
	if (p->list_len < p->line_c)
		return (ft_sprintf(p->buf + i, "%s\n", lsf->name));
	/*if is inside a line*/
	else
		return (ft_sprintf(p->buf + i, "%-*s", p->col_w, lsf->name));
}

void		ls_print_file_columns(t_lsfdata *lsf, t_lsconfig *cfg)
{
	t_lsprint	*p;

	p = &cfg->lsp;
	if (!p->col_c)
		set_columns(cfg);
	--p->list_len;
	bufferize(lsf, p);
	/*if is the last word in the list*/
	if (!p->list_len)
		print_and_destroy(cfg, p);
	else
	{
		if (++p->word_count == p->line_c)
		{
			p->word_count = 0;
			++p->col_count;
		}
	}
}
