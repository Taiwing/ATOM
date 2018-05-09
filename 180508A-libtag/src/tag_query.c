#include "include/tag_query.h"

/*global variables for the recursive query functions*/
struct query_node *root;
char **file_list;
int flags, fc;
size_t size;

static void pors_list(glob_optarg *glo, tagout *out);
static void inquiry(const char *file);
static int rec_inquiry(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);

void tagqtu(glob_optarg *glo, tagout *out)
{
	flags = glo->flags;
	size = 0;
	fc = 0;
	if(flags & OPT_QUERY && valid_query(glo->query))
		root = build_qtree(glo->query, strlen(glo->query));

	for(int i = 0; i < glo->fc; i++)
	{
		if(!filerrck(glo->files[i], OPT_QUERY))
		{
			if(flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_inquiry, 20, 0);
			else if(flags & OPT_ALL || !isdir(glo->files[i]))
				inquiry(glo->files[i]);
		}
		else if(!(flags & LCALL)) puts("");
	}

	pors_list(glo, out);

	if(flags & OPT_QUERY)
		free(root);
}

static void pors_list(glob_optarg *glo, tagout *out) /*print or save list*/
{
	qsort(file_list, fc, sizeof(char *), cmp);

	/*if not any core option (s, d, g, l, S or R)*/
	if(!(flags << (sizeof(int)*8-6)) && !(flags & LCALL))
		for(int i = 0; i < fc; i++) /*print list*/
			puts(file_list[i]);
	else if(!(flags & LCALL)) /*if it is not a lib call*/
	{
		glo->fc = fc;
		glo->files = file_list;
		glo->flags &= ~OPT_RECURSIVE; /*removes recursive option*/
	}
	else
	{
		out->fc = fc;
		out->file_list = file_list;
	}
}

static void inquiry(const char *file)
{
	char *list = (char *)salloc(XATTR_LIST_MAX);
	size_t n = listxattr(file, list, XATTR_LIST_MAX);

	/*test if the file matches the query*/
	if((flags & OPT_QUERY && test_node(root, list, n, file))
		|| (flags & OPT_UNTAGGED && n == 0)
		|| (flags & OPT_TAGGED && n))
	{
		walloc((void ***)&file_list, &size, &fc);
		file_list[fc-1] = strcpy((char *)salloc(strlen(file)+1), file);
	}

	free(list);
}

static int rec_inquiry(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	if(flags & OPT_ALL || S_ISREG(sb->st_mode))
		inquiry(fpath);
	return 0;
}
