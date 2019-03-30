/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:06:56 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 15:42:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ACL_H
# define GET_ACL_H

# include "lsconfig.h"
# include <sys/acl.h>
# include <sys/param.h>
# include <membership.h>
# include <uuid/uuid.h>

# define MAXNAMETAG		(MAXLOGNAME + 6)	/* + strlen("group:")*/
# define MAXTYPE		8					/*strlen("unknown")*/
# define MAXPERMS		256					/*length of every perm together*/

typedef struct		s_acl_info
{
	/*fetch acl infos*/
	acl_entry_t		entry;
	uuid_t			*applicable;
	acl_tag_t		tag;
	acl_flagset_t	flags;
	acl_permset_t	perms;
	/*print acl infos*/
	char			name[MAXNAMETAG];
	int				inherited;
	char			type[MAXTYPE];
	char			perms_str[MAXPERMS];
}					t_acl_info;

int		get_acl(char *path, t_lsfdata *lsf, t_lsconfig *cfg);
int		get_acl_info(t_acl_info *aclinf);
void	get_acl_string(t_acl_info *aclinf, int isdir);

#endif
