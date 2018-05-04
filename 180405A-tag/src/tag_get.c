#include "include/tag.h"

int opt_all;

static void printx(const char *file);
static int rec_printx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);
static void print_date(date_s *date);

void tagg(glob_optarg *glo)
{
	opt_all = (glo->flags & OPT_ALL);

	for(int i = 0; i < glo->fc; i++)
	{
		if(!filerrck(glo->files[i], OPT_GET))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_printx, 20, 0);
			else if(opt_all || !isdir(glo->files[i]))
				printx(glo->files[i]);
		}
		else puts("");
	}
}

static void printx(const char *file)
{
	char *list = (char *)salloc(XATTR_LIST_MAX);
	char *v = (char *)salloc(XATTR_SIZE_MAX);
	size_t n = listxattr(file, list, XATTR_LIST_MAX), lv;

	if(n)
	{
		char **splitl = split_list(list, n);
		sort_wordtab(splitl);
		printf("# file: %s\n", file);
		for(int i = 0; splitl[i]; i++)
		{
			memset((void *)v, 0, XATTR_SIZE_MAX);
			printf("%s", splitl[i]+LU); /*prints tag name without "user." prefix*/
			lv = getxattr(file, splitl[i], (void *)v, XATTR_SIZE_MAX);
			if(lv)
			{
				R_TAG val;
				uint8_t format = read_value(v, lv, &val);
				switch(format)
				{
					case LINK:
						printf(" = %s", (char *)(val.str));
						free(val.str);
						break;
					case STR:
						printf(" = \"%s\"", (char *)(val.str));
						free(val.str);
						break;
					case INT:
						printf(" = %"PRId64"", val.inb);
						break;
					case DATE:
						print_date(val.date);
						free(val.date);
						break;
				}
			}
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
	if(S_ISREG(sb->st_mode) || opt_all)
		printx(fpath);
	return 0;
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
