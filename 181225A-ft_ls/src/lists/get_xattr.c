/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:03:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 11:59:16 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_errors.h"
#include <sys/xattr.h>

static t_list	*add_attr_to_list(char *path, char *attr, ssize_t attr_size)
{
	int		l;
	ssize_t	i;
	ssize_t	size;
	t_list	*lst;
	char	buf[256];

	i = 0;
	lst = NULL;
	while (i < attr_size)
	{
		l = ft_strlen(attr + i);
		if ((size = getxattr(path, attr + i, NULL, 0, 0, XATTR_NOFOLLOW)) >= 0)
		{
			ft_sprintf(buf, "\t%s\t%4zd", attr + i, size);
			ft_lst_push_back(&lst, buf, ft_strlen(buf) + 1);
		}
		i += l + 1;
	}
	return (lst);
}

int			get_xattr(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	ssize_t	size;
	char	*attr;

	(void)cfg;
	if ((size = listxattr(path, 0, 0, XATTR_NOFOLLOW)) > 0)
	{
		attr = (char *)ft_secmalloc(size * sizeof(char));
		if (listxattr(path, attr, size, XATTR_NOFOLLOW) == size)
			lsf->ls_attr_acl = add_attr_to_list(path, attr, size);
		free(heap_collector(attr, HS_GET));
	}
	return (lsf->ls_attr_acl ? 2 : 0);
}
