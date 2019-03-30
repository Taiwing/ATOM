/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acl_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:00:14 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 14:55:09 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_acl.h"
#include "g_acl_perms.h"

static void	uuid_to_name(uuid_t *uu, char *name)
{
	int				is_gid;
	struct group	*grp;
	struct passwd	*pass;
	uid_t			id;

	is_gid = -1;
	grp = NULL;
	pass = NULL;
	if (!mbr_uuid_to_id(*uu, &id, &is_gid))
	{
		if (is_gid == ID_TYPE_UID && (pass = getpwuid(id)))
				ft_snprintf(name, MAXNAMETAG, "%s:%s", "user", pass->pw_name);
		else if (is_gid == ID_TYPE_GID && (grp = getgrgid((gid_t)id)))
				ft_snprintf(name, MAXNAMETAG, "%s:%s", "group", grp->gr_name);
	}
	if (!grp && !pass)
		uuid_unparse_upper(*uu, name);
}

int			get_acl_info(t_acl_info *aclinf)
{
	if (!(aclinf->applicable = acl_get_qualifier(aclinf->entry)))
		return (1);
	else
		acl_heap_collector(aclinf->applicable, HS_ADD);
	if (acl_get_tag_type(aclinf->entry, &aclinf->tag)
		|| acl_get_flagset_np(aclinf->entry, &aclinf->flags)
		|| acl_get_permset(aclinf->entry, &aclinf->perms))
	{
		acl_free(acl_heap_collector(aclinf->applicable, HS_GET));
		return (1);
	}
	return (0);
}

static void	get_perms(t_acl_info *aclinf, int isdir)
{
	int	i;
	int	first;

	i = -1;
	first = 0;
	while (g_acl_perms[++i].name)
	{
		if (acl_get_perm_np(aclinf->perms, g_acl_perms[i].perm)
			&& (g_acl_perms[i].flags & (isdir ? ACL_PERM_DIR : ACL_PERM_FILE)))
			ft_sprintf(aclinf->perms_str + ft_strlen(aclinf->perms_str), "%s%s",
						first++ ? "," : "", g_acl_perms[i].name);
	}
	i = -1;
	while (g_acl_flags[++i].name)
	{
		if (acl_get_flag_np(aclinf->flags, g_acl_flags[i].flag)
			&& (g_acl_flags[i].flags & (isdir ? ACL_PERM_DIR : ACL_PERM_FILE)))
			ft_sprintf(aclinf->perms_str + ft_strlen(aclinf->perms_str), "%s%s",
						first++ ? "," : "", g_acl_flags[i].name);
	}
}

void		get_acl_string(t_acl_info *aclinf, int isdir)
{
	uuid_to_name(aclinf->applicable, aclinf->name);
	acl_free(acl_heap_collector(aclinf->applicable, HS_GET));
	aclinf->inherited = !!acl_get_flag_np(aclinf->flags, ACL_ENTRY_INHERITED);
	if (aclinf->tag == ACL_EXTENDED_ALLOW)
		ft_strcpy(aclinf->type, "allow");
	else if (aclinf->tag == ACL_EXTENDED_DENY)
		ft_strcpy(aclinf->type, "deny");
	else
		ft_strcpy(aclinf->type, "unknown");
	aclinf->perms_str[0] = 0;
	get_perms(aclinf, isdir);
}
