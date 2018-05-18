#ifndef TAGEX_H
#define TAGEX_H

#include "main.h"

/*sorting modes*/
#define DEFAULT 		0x03	/*SEPTF + ALPHANUM*/
#define SEPTF				0x01	/*separate tags and files*/
#define ALPHANUM		0x02
#define SIZE				0x04
#define TAG_VALUE		0x08

enum types {TAG = 'T', REGFILE = 'F'};

/*elements displayed on the tagex screen*/
typedef struct tag_elem
{
	char *name;		/*displayed name*/
	char *file;		/*file location*/
	size_t size;	/*size of the file and number of elements in a tag_folder*/
	char type;		/*TAG or REGFILE*/
} tag_elem;

void ncint_tagex(char *root_dir);

#endif
