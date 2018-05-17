#include "include/tagex.h"

static void get_raw_vals(char *root_dir, char **qbar, int qbc,
												lout **raw_tags, qout **raw_files);
static qout *get_uniqs(lout *raw_tags, char *query, char *root_dir);
static char *build_query(char **qbar, int qbc);

void ncint_tagex(char *root_dir)
{
	char **query_bar = NULL;						/*tagex "adress" bar*/
	tag_elem **elem_list = NULL;				/*tags and files*/
	int qbc = 0, elc = 0, noexit = 1;
	size_t qbsize = 0, elsize = 0;			/*size of query_bar and elem_list*/
	qout *raw_files = NULL;							/*output of a query call*/
	lout *raw_tags = NULL;							/*output of a list call*/

	while(noexit)
	{
		get_raw_vals(root_dir, query_bar, qbc, &raw_tags, &raw_files);
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
		if(raw_tags->taglist[i]->c == 1) /*TODO: finish this shit*/
		{
			tmp = tag_query(query ? query : raw_tags->taglist[i]->name,
											OPT_RECURSIVE | OPT_ALL, &root_dir, 1);
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
