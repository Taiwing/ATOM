#include "include/tag.h"

gettag **getlist;
size_t size;
int opt_all, gc;

static void getx(const char *file);
static int rec_getx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);
static void print_list(void);
static void print_date(date_s *date);

void tagg(glob_optarg *glo, tagout *out)
{
	opt_all = (glo->flags & OPT_ALL);
	size = 0;
	gc = 0;

	for(int i = 0; i < glo->fc; i++)
	{
		if(!filerrck(glo->files[i], OPT_GET))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_getx, 20, 0);
			else if(opt_all || !isdir(glo->files[i]))
				getx(glo->files[i]);
		}
		else puts("");
	}

	if(!(glo->flags & LCALL))
	{
		print_list();
		free(getlist);
	}
	else
	{
		out->gc = gc;
		out->tag_get = getlist;
	}
}

static void getx(const char *file)
{
	char *list = (char *)salloc(XATTR_LIST_MAX);
	void *v = salloc(XATTR_SIZE_MAX);
	size_t n = listxattr(file, list, XATTR_LIST_MAX), lv;

	if(n)
	{
		walloc((void ***)&getlist, &size, &gc);
		getlist[gc-1] = (gettag *)salloc(sizeof(gettag));
		getlist[gc-1]->file = strcpy((char *)salloc(strlen(file)+1), file);
		getlist[gc-1]->n = n;
		getlist[gc-1]->list = split_list(list, n);
		getlist[gc-1]->format = (char *)salloc(n);
		getlist[gc-1]->values = (R_TAG **)salloc(n * sizeof(R_TAG *));
		sort_wordtab(getlist[gc-1]->list);
		for(int i = 0; getlist[gc-1]->list[i]; i++)
		{
			memset(v, 0, XATTR_SIZE_MAX);
			lv = getxattr(file, getlist[gc-1]->list[i], v, XATTR_SIZE_MAX);
			if(lv)
			{
				getlist[gc-1]->values[i] = (R_TAG *)salloc(sizeof(R_TAG));
				getlist[gc-1]->format[i] = read_value(v, lv, getlist[gc-1]->values[i]);
			}
			else
			{
				getlist[gc-1]->values[i] = NULL;
				getlist[gc-1]->format[i] = 0;
			}
		}
	}

	free(list);
	free(v);
}

static int rec_getx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	if(S_ISREG(sb->st_mode) || opt_all)
		getx(fpath);
	return 0;
}

static void print_list(void)
{
	for(int i = 0; i < gc; i++)
	{
		printf("# file: %s\n", getlist[i]->file);
		for(int j = 0; j < getlist[i]->n; j++)
		{
			printf("%s", getlist[i]->list[j]+LU);
			switch(getlist[i]->format[i])
			{
				case LINK: printf(" = %s", (char *)(getlist[i]->values[j]->str));
					break;
				case STR: printf(" = \"%s\"", (char *)(getlist[i]->values[j]->str));
					break;
				case INT: printf(" = %"PRId64"", getlist[i]->values[j]->inb);
					break;
				case DATE: print_date(getlist[i]->values[j]->date);
					break;
			}
			puts("");
		}
		puts("");
	}
}

static void print_date(date_s *date)
{
	if(date->day < 10)
		printf(" = 0%"PRIu8"/", date->day);
	else
		printf(" = %"PRIu8"/", date->day);
	if(date->month < 10)
		printf("0%"PRIu8"/", date->month);
	else
		printf("%"PRIu8"/", date->month);

	if(date->year > 999 || date->year < -999)
		printf("%"PRId64"", date->year);
	else
	{
		uint64_t abs_year = date->year < 0 ? (uint64_t)(date->year * (-1))
																			 : (uint64_t)date->year;
		if(date->year < 0)
			printf("-");
		for(uint64_t cmp = 1; (cmp * abs_year) < 1000 && cmp < 1000; cmp *= 10)
			printf("0");
		printf("%"PRIu64"", abs_year);
	}
}
