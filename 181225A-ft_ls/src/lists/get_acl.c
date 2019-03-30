/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:13:36 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 14:49:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_acl.h"

static void	add_acl_to_list(acl_t acl, t_acl_info *aclinf,
							int isdir, t_list **lst)
{
	char	*ptr;
	int		index;

	index = 0;
	while (!acl_get_entry(acl, !aclinf->entry ?
			ACL_FIRST_ENTRY : ACL_NEXT_ENTRY, &aclinf->entry))
	{
		if (!get_acl_info(aclinf))
		{
			get_acl_string(aclinf, isdir);
			ft_asprintf(&ptr, " %d: %s%s %s %s", index, aclinf->name,
					aclinf->inherited ? " inherited" : "", aclinf->type,
					aclinf->perms_str);
			ft_lst_push_back(lst, ptr, ft_strlen(ptr) + 1);
			free(heap_collector(ptr, HS_GET));
		}
		++index;
	}
}

int			get_acl(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	acl_t		acl;
	t_acl_info	aclinf;

	(void)cfg;
	if ((acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_heap_collector(acl, HS_ADD);
		aclinf.entry = NULL;
		add_acl_to_list(acl, &aclinf, lsf->isdir, &lsf->ls_attr_acl);
		acl_free(acl_heap_collector(acl, HS_GET));
		return (1);
	}
	return (0);
}
