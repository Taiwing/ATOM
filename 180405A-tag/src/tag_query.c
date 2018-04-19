#include "include/tag_query.h"

struct query_node *root;
char **file_list;
int opt_all, no_sdgl, fc;
size_t size;

static void inquiry(const char *file);
static int rec_inquiry(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);

void tagq(glob_optarg *glo)
{
	if(valid_query(glo->query))
		root = build_qtree(glo->query, strlen(glo->query));
	opt_all = (glo->flags & OPT_ALL);
	no_sdgl = !(glo->flags << (sizeof(int)*8-4));
	size = 0;
	fc = 0;

	for(int i = 0; i < glo->fc; i++)
	{
		if(!filerrck(glo->files[i], OPT_QUERY))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_inquiry, 20, 0);
			else if(opt_all || !isdir(glo->files[i]))
				inquiry(glo->files[i]);
		}
		else puts("");
	}

	qsort(file_list, fc, sizeof(char *), cmp);

	if(no_sdgl)
		for(int i = 0; i < fc; i++)
			puts(file_list[i]);
	else
	{
		glo->files = file_list;
		glo->fc = fc;
		glo->flags &= ~OPT_RECURSIVE; /*removes recursive option*/
	}

	free(root);
}

static void inquiry(const char *file)
{
	char *list = (char *)smalloc(XATTR_LIST_MAX);
	size_t n = listxattr(file, list, XATTR_LIST_MAX);

	if(test_node(root, list, n)) /*test if the file matches the query*/
	{
		high_water_alloc((void ***)&file_list, &size, &fc);
		file_list[fc-1] = strcpy((char *)smalloc(strlen(file)+1), file);
	}

	free(list);
}

static int rec_inquiry(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	if(S_ISREG(sb->st_mode) || opt_all)
		inquiry(fpath);
	return 0;
}
