#include "include/tagex.h"

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
		/*fetch tags and files data*/
		get_raw_vals(root_dir, query_bar, qbc, &raw_tags, &raw_files);
		update_elem_list(&elem_list, &elsize, &elc, &raw_tags, &raw_files);
		sort_elem_list(elem_list, elc, sortmode);

		/*TODO: interface loop where the magic happens*/
	}
}
