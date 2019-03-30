#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h> 	//MAXLOGNAME
#include <err.h>		//err() (yeah, no shit)
#include <membership.h>	//mbr_uuid_to_id
#include <grp.h>		//getgrgid
#include <pwd.h>		//getpwuid
#include <sys/acl.h>
#include <sys/xattr.h>
#include <uuid/uuid.h>

/*
 *  * print access control list
 *   */

#define ACL_PERM_DIR	1
#define ACL_PERM_FILE	2
#define MAXNAMETAG (MAXLOGNAME + 6) /* + strlen("group:") */

static struct {
	acl_perm_t	perm;
	char		*name;
	int		flags;
} acl_perms[] = {
	{ACL_READ_DATA,		"read",		ACL_PERM_FILE},
	{ACL_LIST_DIRECTORY,	"list",		ACL_PERM_DIR},
	{ACL_WRITE_DATA,	"write",	ACL_PERM_FILE},
	{ACL_ADD_FILE,		"add_file",	ACL_PERM_DIR},
	{ACL_EXECUTE,		"execute",	ACL_PERM_FILE},
	{ACL_SEARCH,		"search",	ACL_PERM_DIR},
	{ACL_DELETE,		"delete",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_APPEND_DATA,	"append",	ACL_PERM_FILE},
	{ACL_ADD_SUBDIRECTORY,	"add_subdirectory", ACL_PERM_DIR},
	{ACL_DELETE_CHILD,	"delete_child",	ACL_PERM_DIR},
	{ACL_READ_ATTRIBUTES,	"readattr",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_ATTRIBUTES,	"writeattr",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_READ_EXTATTRIBUTES, "readextattr",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_EXTATTRIBUTES, "writeextattr", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_READ_SECURITY,	"readsecurity",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_SECURITY,	"writesecurity", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_CHANGE_OWNER,	"chown",	ACL_PERM_FILE | ACL_PERM_DIR},
	{0, NULL, 0}
};

static struct {
	acl_flag_t	flag;
	char		*name;
	int		flags;
} acl_flags[] = {
	{ACL_ENTRY_FILE_INHERIT, 	"file_inherit",		ACL_PERM_DIR},
	{ACL_ENTRY_DIRECTORY_INHERIT,	"directory_inherit",	ACL_PERM_DIR},
	{ACL_ENTRY_LIMIT_INHERIT,	"limit_inherit",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_ENTRY_ONLY_INHERIT,	"only_inherit",		ACL_PERM_DIR},
	{0, NULL, 0}
};

static char *uuid_to_name(uuid_t *uu) 
{
	int is_gid = -1;
	struct group *tgrp = NULL;
	struct passwd *tpass = NULL;
	char *name = NULL;
	uid_t id;


	name = (char *) malloc(MAXNAMETAG);

	if (NULL == name)
		err(1, "malloc");

	if (0 != mbr_uuid_to_id(*uu, &id, &is_gid))
		goto errout;

	switch (is_gid) {
		case ID_TYPE_UID:
			tpass = getpwuid(id);
			if (!tpass) {
				goto errout;
			}
			snprintf(name, MAXNAMETAG, "%s:%s", "user", tpass->pw_name);
			break;
		case ID_TYPE_GID:
			tgrp = getgrgid((gid_t) id);
			if (!tgrp) {
				goto errout;
			}
			snprintf(name, MAXNAMETAG, "%s:%s", "group", tgrp->gr_name);
			break;
		default:
			goto errout;
	}
	return name;
errout:
	uuid_unparse_upper(*uu, name);
	return name;
}

static void	printacl(acl_t acl, int isdir)
{
	acl_entry_t	entry = NULL;
	int		index;
	uuid_t		*applicable;
	char		*name = NULL;
	acl_tag_t	tag;
	acl_flagset_t	flags;
	acl_permset_t	perms;
	char		*type;
	int		i, first;


	for (index = 0;
			acl_get_entry(acl, entry == NULL ? ACL_FIRST_ENTRY : ACL_NEXT_ENTRY, &entry) == 0;
			index++) {
		if ((applicable = (uuid_t *) acl_get_qualifier(entry)) == NULL)
			continue;
		if (acl_get_tag_type(entry, &tag) != 0)
			continue;
		if (acl_get_flagset_np(entry, &flags) != 0)
			continue;
		if (acl_get_permset(entry, &perms) != 0)
			continue;
		name = uuid_to_name(applicable);
		acl_free(applicable);

		switch(tag) {
			case ACL_EXTENDED_ALLOW:
				type = "allow";
				break;
			case ACL_EXTENDED_DENY:
				type = "deny";
				break;
			default:
				type = "unknown";
		}

		(void)printf(" %d: %s%s %s ",
				index,
				name,
				acl_get_flag_np(flags, ACL_ENTRY_INHERITED) ? " inherited" : "",
				type);

		if (name)
			free(name);

		for (i = 0, first = 0; acl_perms[i].name != NULL; i++) {
			if (acl_get_perm_np(perms, acl_perms[i].perm) == 0)
				continue;
			if (!(acl_perms[i].flags & (isdir ? ACL_PERM_DIR : ACL_PERM_FILE)))
				continue;
			(void)printf("%s%s", first++ ? "," : "", acl_perms[i].name);
		}
		for (i = 0; acl_flags[i].name != NULL; i++) {
			if (acl_get_flag_np(flags, acl_flags[i].flag) == 0)
				continue;
			if (!(acl_flags[i].flags & (isdir ? ACL_PERM_DIR : ACL_PERM_FILE)))
				continue;
			(void)printf("%s%s", first++ ? "," : "", acl_flags[i].name);
		}

		(void)putchar('\n');
	}

}

int main(int argc, const char * argv[])
{
	int 	i = 1;
	ssize_t	ext;
	char	*attr;
	ssize_t	size;
	struct stat	buf;

	while (i < argc) {
		printf("%s\n",argv[i]);
		acl_t acl = acl_get_file(argv[i], ACL_TYPE_EXTENDED);
		if (acl) {
			lstat(argv[i], &buf);
			printacl(acl, S_ISDIR(buf.st_mode));
			acl_free(acl);
		}
		printf("extended attributes: ");
		if ((ext = listxattr(argv[i], 0, 0, XATTR_NOFOLLOW)) > 0)
		{
			attr = (char *)malloc(ext + 1);
			printf("yes:\n");
			size = 0;
			if (listxattr(argv[i], attr, ext + 1, XATTR_NOFOLLOW) > 0)
			{
				while (size < ext)
				{
					printf("\t%s\t%4zd\n", attr + size,
							getxattr(argv[i], attr + size, NULL, 0, 0, XATTR_NOFOLLOW));
					size += strlen(attr + size) + 1;
				}
			}
			free(attr);
		}
		else if (!ext)
			printf("no\n");
		else
			printf("error\n");
		i++;
	}
	return 0;
}
