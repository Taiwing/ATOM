/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xattracl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:17:23 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 05:16:42 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_acl.h"
#include "get_xattr.h"
#include <sys/acl.h>
#include <sys/xattr.h>

void		get_xattracl(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	acl_t	acl;

	(void)cfg;
	lsf->ls_attr_acl = NULL;
	lsf->xattr_acl = listxattr(path, 0, 0, XATTR_NOFOLLOW) > 0 ? 2 : 0;
	if (!lsf->xattr_acl && (acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		lsf->xattr_acl = 1;
		acl_free(acl);
	}
}

void		get_xattr_only(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	acl_t	acl;

	lsf->ls_attr_acl = NULL;
	lsf->xattr_acl = get_xattr(path, lsf, cfg);
	if (!lsf->xattr_acl && (acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		lsf->xattr_acl = 1;
		acl_free(acl);
	}
}

void		get_acl_only(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	lsf->ls_attr_acl = NULL;
	lsf->xattr_acl = listxattr(path, 0, 0, XATTR_NOFOLLOW) > 0 ? 2 : 0;
	lsf->xattr_acl = get_acl(path, lsf, cfg) && !lsf->xattr_acl ?
					1 : lsf->xattr_acl;
}

void		get_all_xattracl(char *path, t_lsfdata *lsf, t_lsconfig *cfg)
{
	lsf->ls_attr_acl = NULL;
	lsf->xattr_acl = get_xattr(path, lsf, cfg);
	lsf->xattr_acl = get_acl(path, lsf, cfg) && !lsf->xattr_acl ?
					1 : lsf->xattr_acl;
}
