/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:46:42 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/06 20:51:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsconfig.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

void		put_opendir_error(char *path, t_lsconfig *cfg)
{
	char	*tmp;

	flush_pbuf(&cfg->buf);
	/*
	** this leads to an error when path ends with a '/'
	** where there is no directory name, but since the error
	** is in the original mac os X ls, I am gonna let it there
	*/
	while ((tmp = ft_strchr(path, '/')))
		path = tmp + 1;
	ft_dprintf(2, "ft_ls: %s: ", path);
	perror(NULL);
	cfg->ret = 1;
}

void		add_error(char *path, t_lsconfig *cfg)
{
	char	*serr;
	char	*err;
	int		len;
	
	//build error string
	serr = strerror(errno);
	len = 7 + ft_strlen(path) + 2 + ft_strlen(serr);
	err = ft_strnew(len);
	ft_strcat(err, "ft_ls: ");
	ft_strcat(err, path);
	ft_strcat(err, ": ");
	ft_strcat(err, serr);
	//add it to the ls_errors list
	ft_lst_push_back(&cfg->ls_errors, (void *)err, len + 1);
	free(heap_collector(err, HS_GET));
}

static int	cmp_errs(void *s1, void *s2)
{
	return (ft_strcmp((char *)s1, (char *)s2));
}

void		print_errors(t_lsconfig *cfg)
{
	if (cfg->ls_errors)
	{
		flush_pbuf(&cfg->buf);
		cfg->ret = 1;
		//sort if need be
		if (cfg->sortf)
			ft_lst_quicksort(cfg->ls_errors,
				ft_lst_size(cfg->ls_errors), cmp_errs);
		//print every error and destroy each element
		while (cfg->ls_errors)
		{
			ft_dprintf(2, "%s\n", (char *)cfg->ls_errors->content);
			ft_lst_discard(NULL, &cfg->ls_errors);
		}
	}
}
