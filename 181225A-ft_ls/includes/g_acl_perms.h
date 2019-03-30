/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_acl_perms.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:23:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 15:40:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_ACL_PERMS_H
# define G_ACL_PERMS_H

# include <string.h>
# include <sys/types.h>
# include <sys/acl.h>

# define ACL_PERM_DIR	1
# define ACL_PERM_FILE	2

typedef struct			s_aclperm
{
	acl_perm_t			perm;
	char				*name;
	int					flags;
}						t_aclperm;

typedef struct			s_aclflag
{
	acl_flag_t			flag;
	char				*name;
	int					flags;
}						t_aclflag;

extern const t_aclperm	g_acl_perms[18];
extern const t_aclflag	g_acl_flags[5];

#endif
