#include "tag.h"

static void printx(const char *file);
static int rec_printx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);

void tagl(glob_optarg *glo)
{
	for(int i = 0; i < glo->fc; i++)
	{
		if(!filerrck(glo->files[i], OPT_LIST))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_printx, 20, 0);
			else
				printx(glo->files[i]);
		}
		else puts("");
	}
}

static void printx(const char *file)
{
	char *list = (char *)malloc(1024), *v = (char *)malloc(512);
	size_t n = listxattr(file, list, 1024), lv;

	if(n)
	{
		char **splitl = split_list(list, n);
		sort_wordtab(splitl);
		printf("# file: %s\n", file);
		for(int i = 0; splitl[i]; i++)
		{
			memset((void *)v, 0, 512);
			printf("%s", splitl[i]);
			lv = getxattr(file, splitl[i], (void *)v, 512);
			if(lv)
				printf("=\"%s\"", v);
			puts("");
		}
		free(splitl);
		puts("");
	}

	free(list);
	free(v);
}

static int rec_printx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	printx(fpath);
	return 0;
}
