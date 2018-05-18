#include "include/tagex.h"

static void get_raw_vals(char *root_dir, char **qbar, int qbc,
												lout **raw_tags, qout **raw_files);
static qout *get_uniqs(lout *raw_tags, char *query, char *root_dir);
static char *build_query(char **qbar, int qbc);
static void update_elem_list(tag_elem ***elem_list, size_t *elsize, int *elc,
														 lout **raw_tags, qout **raw_files);
void sort_elem_list(tag_elem **elem_list, int elc, uint8_t sortmode);

void ncint_tagex(char *root_dir)
{
	char **query_bar = NULL;						/*tagex "adress" bar*/
	tag_elem **elem_list = NULL;				/*tags and files*/
	int qbc = 0, elc = 0, noexit = 1;
	size_t qbsize = 0, elsize = 0;			/*size of query_bar and elem_list*/
	uint8_t sortmode = DEFAULT;
	qout *raw_files = NULL;							/*output of a query call*/
	lout *raw_tags = NULL;							/*output of a list call*/

	while(noexit)
	{
		get_raw_vals(root_dir, query_bar, qbc, &raw_tags, &raw_files);
		update_elem_list(&elem_list, &elsize, &elc, &raw_tags, &raw_files);
		sort_elem_list(elem_list, elc, sortmode);

	}
}

static void get_raw_vals(char *root_dir, char **qbar, int qbc,
												lout **raw_tags, qout **raw_files)
{
	if(qbar)
	{
		/*build query and list call*/
		char *query = build_query(qbar, qbc);
		*raw_tags = tag_list(OPT_RECURSIVE | OPT_ALL, &root_dir, 1);
		*raw_files = get_uniqs(*raw_tags, query, root_dir);
	}
	else
	{
		*raw_tags = tag_list(OPT_RECURSIVE | OPT_ALL, &root_dir, 1);
		*raw_files = get_uniqs(*raw_tags, NULL, root_dir);
	}
}

static qout *get_uniqs(lout *raw_tags, char *query, char *root_dir)
{
	qout *out = (qout *)salloc(sizeof(qout)), *tmp = NULL;
	size_t flsize = 0;
	out->file_list = NULL;
	out->fc = 0;

	for(int i = 1; i < raw_tags->tc; i++)
		if(raw_tags->taglist[i]->c == 1)
		{
			char *q = NULL;
			if(query) /*add the tag name to the query*/
			{
				q = (char *)salloc(strlen(query)+4);
				strcpy(q, query);
				strcat(q, "&(");
				strcat(q, raw_tags->taglist[i]->name);
				strcat(q, ")");
			}
			tmp = tag_query(query ? q : raw_tags->taglist[i]->name,
											OPT_RECURSIVE | OPT_ALL, &root_dir, 1);

			walloc((void ***)&(out->file_list), &flsize, &(out->fc));
			out->file_list[out->fc-1] = tmp->file_list[0];
			tmp->file_list[0] = NULL; /*to avoid freeing*/

			if(q) free(q);
			free(tmp);
		}

	if(out->fc == 0)
	{
		free(out);
		return NULL;
	}
	else
		return out;
}

static char *build_query(char **qbar, int qbc)
{
	if(qbc < 1)
		return NULL;
	else if(qbc == 1)
		return strcpy((char *)salloc(strlen(*qbar)+1), *qbar);
	else
	{
		char *ret;
		int l = 0, c = 0;
		for(int i = 0; i < qbc; i++)
			l += strlen(qbar[i]) + (i < qbc-1 ? 3 : 2);
		ret = (char *)salloc(l+1);
		for(int i = 0; i < qbc; i++)
			for(int j = 0; 1; j++)
			{
				if(j == 0)
					ret[c++] = '(';
				ret[c++] = qbar[i][j] ? qbar[i][j] : ')';
				if(qbar[i][j] == '\0')
					ret[c++] = i < qbc-1 ? '&' : '\0';
			}
		return ret;
	}
}

static void update_elem_list(tag_elem ***elem_list, size_t *elsize, int *elc,
														 lout **raw_tags, qout **raw_files)
{
	if(*raw_tags)
	{
		for(int i = 0; i < (*raw_tags)->tc; i++)
		{
			tag_elem *new = (tag_elem *)salloc(sizeof(tag_elem));
			new->name = (*raw_tags)->taglist[i]->name;
			(*raw_tags)->taglist[i]->name = NULL; /*to avoid freeing*/
			new->size = (*raw_tags)->taglist[i]->c;
			new->type = TAG;
			walloc((void ***)elem_list, elsize, elc);
			(*elem_list)[(*elc)-1] = new;
		}
		free(*raw_tags);
		*raw_tags = NULL;
	}

	if(*raw_files)
	{
		for(int i = 0; i < (*raw_files)->fc; i++)
		{
			int j;
			struct stat file_stat;
			tag_elem *new = (tag_elem *)salloc(sizeof(tag_elem));
			new->file = (*raw_files)->file_list[i];
			(*raw_files)->file_list[i] = NULL; /*to avoid freeing*/
			for(j = strlen(new->file)-1; j >= 0 && new->file[j] != '/'; j--);
			new->name = new->file[j] == '/' ? &(new->file[j+1]) : new->file;
			stat(new->file, &file_stat);
			new->size = (size_t)file_stat.st_size;
			new->type = REGFILE;
			walloc((void ***)elem_list, elsize, elc);
			(*elem_list)[(*elc)-1] = new;
		}
		free(*raw_tags);
		*raw_tags = NULL;
	}
}

/*TODO: implement tagvalue_sort*/
void sort_elem_list(tag_elem **elem_list, int elc, uint8_t sortmode)
{
	if(sortmode & SEPTF)
		septf_sort(elem_list, elc);
	if(sortmode & ALPHANUM || sortmode & TAG_VALUE) /*temp*/
		alphanum_sort(elem_list, elc, sortmode & SEPTF);
	if(sortmode & SIZE)
		size_sort(elem_list, elc, sortmode & SEPTF);
}
