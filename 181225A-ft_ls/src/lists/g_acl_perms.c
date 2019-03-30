/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_acl_perms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:23:27 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 15:46:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_acl_perms.h"

const t_aclperm	g_acl_perms[] = {
	{ACL_READ_DATA, "read", ACL_PERM_FILE},
	{ACL_LIST_DIRECTORY, "list", ACL_PERM_DIR},
	{ACL_WRITE_DATA, "write", ACL_PERM_FILE},
	{ACL_ADD_FILE, "add_file", ACL_PERM_DIR},
	{ACL_EXECUTE, "execute", ACL_PERM_FILE},
	{ACL_SEARCH, "search", ACL_PERM_DIR},
	{ACL_DELETE, "delete", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_APPEND_DATA, "append", ACL_PERM_FILE},
	{ACL_ADD_SUBDIRECTORY, "add_subdirectory", ACL_PERM_DIR},
	{ACL_DELETE_CHILD, "delete_child", ACL_PERM_DIR},
	{ACL_READ_ATTRIBUTES, "readattr", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_ATTRIBUTES, "writeattr", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_READ_EXTATTRIBUTES, "readextattr", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_EXTATTRIBUTES, "writeextattr", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_READ_SECURITY, "readsecurity", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_SECURITY, "writesecurity", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_CHANGE_OWNER, "chown", ACL_PERM_FILE | ACL_PERM_DIR},
	{0, NULL, 0}
};

const t_aclflag	g_acl_flags[] = {
	{ACL_ENTRY_FILE_INHERIT, "file_inherit", ACL_PERM_DIR},
	{ACL_ENTRY_DIRECTORY_INHERIT, "directory_inherit", ACL_PERM_DIR},
	{ACL_ENTRY_LIMIT_INHERIT, "limit_inherit", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_ENTRY_ONLY_INHERIT, "only_inherit", ACL_PERM_DIR},
	{0, NULL, 0}
};
