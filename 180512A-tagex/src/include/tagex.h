#ifndef TAGEX_H
#define TAGEX_H

#include "main.h"

enum types {TAG = 'T', REGFILE = 'F'};

/*elements displayed on the tagex screen*/
typedef struct tag_elem
{
	char *name;		/*displayed name*/
	char *file;		/*file location*/
	size_t size;	/*size of the file and number of elemets in a tag_folder*/
	char type;
} tag_elem;

void ncint_tagex(char *root_dir);

#endif
