#include "include/tag.h"

typedef struct tag
{
	char *name;		/*tag name*/
	int c;				/*count*/
} tag;

int opt_all, tc;
size_t size;
tag **tag_list;

static tag *add_tag(char *name);
static void compare_lists(char **splitl);
static void print_list(void);
static void listx(const char *file);
static int rec_listx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);

void tagl(glob_optarg *glo)
{
	opt_all = (glo->flags & OPT_ALL);
	tc = 0;
	size = 0;
	walloc((void ***)&tag_list, &size, &tc);
	tag_list[0] = add_tag("user.UNTAGGED");
	tag_list[0]->c = 0;

	for(int i = 0; i < glo->fc; i++)
	{
		if(!filerrck(glo->files[i], OPT_LIST))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_listx, 20, 0);
			else if(opt_all || !isdir(glo->files[i]))
				listx(glo->files[i]);
		}
	}

	print_list();
	free(tag_list);
}

static tag *add_tag(char *name)
{
	tag *tp = (tag *)salloc(sizeof(tag));

	tp->name = (char *)salloc(strlen(name)+1);
	strcpy(tp->name, name);
	tp->c = 1;

	return tp;
}

static void compare_lists(char **splitl)
{
	int i = 0, j = 1, cmp;
	tag *p;
	for(; splitl[i]; i++)
	{
		for(; j < tc && (cmp = strcmp(splitl[i], tag_list[j]->name)) > 0; j++);
		if(j == tc)
		{
			walloc((void ***)&tag_list, &size, &tc);
			tag_list[j] = add_tag(splitl[i]);
		}
		else if(cmp == 0)
			(tag_list[j]->c)++;
		else if(cmp < 0)
		{
			walloc((void ***)&tag_list, &size, &tc);
			tag_list[tc-1] = add_tag(splitl[i]);
			for(int k = tc-1; k > j; k--)
			{
				p = tag_list[k];
				tag_list[k] = tag_list[k-1];
				tag_list[k-1] = p;
			}
		}
	}
}

static void print_list(void)
{
	size_t biggest = 0;
	size_t *len = (size_t *)salloc(tc * sizeof(size_t));
	for(int i = 0; i < tc; i++)
	{
		len[i] = strlen(tag_list[i]->name) - LU;
		biggest = len[i] > biggest ? len[i] : biggest;
	}

	for(int i = 0; i < tc; i++)
	{
		/*really cool trick with printf to print columns*/
		if(tag_list[i]->c > 0)
			printf("%s%*d\n", tag_list[i]->name+LU,
						(int)(len[i] < biggest ? biggest-len[i]+7 : 7),
						tag_list[i]->c);
	}

	free(len);
}

static void listx(const char *file)
{
	char *list = (char *)salloc(XATTR_LIST_MAX);
	size_t n = listxattr(file, list, XATTR_LIST_MAX);

	if(n)
	{
		char **splitl = split_list(list, n);
		sort_wordtab(splitl);
		compare_lists(splitl);
		free(splitl);
	}
	else
		(tag_list[0]->c)++;

	free(list);
}

static int rec_listx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	if(S_ISREG(sb->st_mode) || opt_all)
		listx(fpath);
	return 0;
}
