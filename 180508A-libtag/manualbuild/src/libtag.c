#include "include/libtag.h"

qout *tag_query(char *query, int flags, char **files, int fc)
{
	qout *out = (qout *)salloc(sizeof(qout));
	glob_optarg *in = (glob_optarg *)salloc(sizeof(glob_optarg));
	in->fc = fc;
	in->query = query;
	in->files = files;
	in->flags = flags | LCALL | OPT_QUERY;

	tagqtu(in, out);
	in->files = NULL; /*to avoid freeing*/
	in->query = NULL; /*same*/
	free(in);

	return out;
}

gout *tag_get(int flags, char **files, int fc)
{
	gout *out = (gout *)salloc(sizeof(gout));
	glob_optarg *in = (glob_optarg *)salloc(sizeof(glob_optarg));
	in->fc = fc;
	in->files = files;
	in->flags = flags | LCALL | OPT_GET;

	tagg(in, out);
	in->files = NULL; /*to avoid freeing the list*/
	free(in);

	return out;
}

lout *tag_list(int flags, char **files, int fc)
{
	lout *out = (lout *)salloc(sizeof(lout));
	glob_optarg *in = (glob_optarg *)salloc(sizeof(glob_optarg));
	in->fc = fc;
	in->files = files;
	in->flags = flags | LCALL | OPT_LIST;

	tagl(in, out);
	in->files = NULL; /*to avoid freeing the list*/
	free(in);

	return out;
}

void tag_set(char *name, char *value, int flags, char **files, int fc)
{
	glob_optarg *in = (glob_optarg *)salloc(sizeof(glob_optarg));
	in->fc = fc;
	in->name = name;
	in->value = value;
	in->files = files;
	in->flags = flags | LCALL | OPT_SET;

	tags(in);
	in->files = NULL; /*to avoid freeing the list*/
	in->name = NULL; /*same*/
	in->value = NULL; /*same*/
	free(in);
}

void tag_delete(char *name, int flags, char **files, int fc)
{
	glob_optarg *in = (glob_optarg *)salloc(sizeof(glob_optarg));
	in->fc = fc;
	in->name = name;
	in->files = files;
	in->flags = flags | LCALL | OPT_DELETE;

	tagd(in);
	in->files = NULL; /*to avoid freeing the list*/
	in->name = NULL; /*same*/
	free(in);
}
