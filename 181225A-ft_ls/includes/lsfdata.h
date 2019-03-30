/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsfdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:28:52 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/26 22:12:30 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSFDATA_H
# define LSFDATA_H

# include <sys/stat.h>		/*for stat struct and functions*/
# include <dirent.h>		/*for opendir, readdir and DIR/dirent structs*/
# include <time.h>			/*to use ctime for a read of stat struct*/
# include <pwd.h>			/*for getpwuid*/
# include <grp.h>			/*for getgrgid*/
# include "libft.h"

/*TODO: add support for extended attributes and ACL*/

/*
** Structure on wich the main chained list is constructed upon. It contains
** all the information ft_ls has about one file.
*/
typedef struct		s_lsfdata
{
	char			name[256];		/*copy from readdir or args*/
	int				isdir;			/*info taken from readdir*/
	struct stat		stats;			/*output from stat*/
	char			*group;			/*from getgrgid*/
	char			*user;			/*from getpwuid*/
	char			*link_target;	/*from readlink*/
	int				xattr_acl;		/*from listxattr or acl_get_link_np*/
	t_list			*ls_attr_acl;	/*from listxattr or acl_get_link_np*/
}					t_lsfdata;

/*
** Structure which contains every info ft_ls has about one directory
*/
typedef struct		s_lsddata
{
	char			*path;
	DIR				*dirp;
	t_list			*ls_files;
}					t_lsddata;

#endif
