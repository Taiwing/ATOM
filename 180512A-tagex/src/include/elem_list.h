#ifndef ELEM_LIST_H
#define ELEM_LIST_H

#include "main.h"

enum types {TAG = 'T', REGFILE = 'F'};

/*elements displayed on the tagex screen*/
typedef struct tag_elem
{
	char *name;		/*displayed name*/
	char *file;		/*file location*/
	size_t size;	/*size of the file and number of elements in a tag_folder*/
	char type;		/*TAG or REGFILE*/
} tag_elem;

void get_raw_vals(char *root_dir, char **qbar, int qbc,
									lout **raw_tags, qout **raw_files);
char *build_query(char **qbar, int qbc);
qout *get_uniqs(lout *raw_tags, char *query, char *root_dir);
void update_elem_list(tag_elem ***elem_list, size_t *elsize, int *elc,
											lout **raw_tags, qout **raw_files);

#endif
