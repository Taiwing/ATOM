#include "include/tag.h"
#include <time.h>

int opt_all;
FILE *td = NULL; /*tag_dump file stream*/

static void savex(const char *file);
static int rec_savex(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);

void tag_save(glob_optarg *glo)
{
	opt_all = (glo->flags & OPT_ALL);

	char filename[256];
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	if(!strftime(filename, 255, "%d%m%Y%H%M%S.td", t))
	{
		perror("strftime");
		exit(EXIT_FAILURE);
	}
	if((td = fopen(filename, "a")) == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < glo->fc; i++)
	{
		if(!filerrck(glo->files[i], OPT_GET))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_savex, 20, 0);
			else if(opt_all || !isdir(glo->files[i]))
				savex(glo->files[i]);
		}
		else puts("");
	}
}

static void savex(const char *file)
{
	char *list = (char *)salloc(XATTR_LIST_MAX);
	void *v = salloc(XATTR_SIZE_MAX);
	ssize_t n = listxattr(file, list, XATTR_LIST_MAX), lv;

	if(n)
	{
		char **splitl = split_list(list, n);
		sort_wordtab(splitl);
		fprintf(td, "# file: %s\n", file);
		for(int i = 0; splitl[i]; i++)
		{
			memset(v, 0, XATTR_SIZE_MAX);
			fprintf(td, "%s", splitl[i]+LU);
			lv = getxattr(file, splitl[i], v, XATTR_SIZE_MAX);
			if(lv > 0)
			{
				fprintf(td, " 0x");
				for(unsigned char *p = (unsigned char *)v; (void *)p < v+lv; p++)
				{
					if(*p < 0x10) fprintf(td, "0");
					fprintf(td, "%x", *p);
				}
			}
			fprintf(td, "\n");
		}
		free(splitl);
		fprintf(td, "\n");
	}

	free(list);
	free(v);
}

static int rec_savex(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	if(S_ISREG(sb->st_mode) || opt_all)
		savex(fpath);
	return 0;
}
