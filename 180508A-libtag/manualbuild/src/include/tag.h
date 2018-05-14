#ifndef TAG_H
#define TAG_H

#define _XOPEN_SOURCE 700 	/*required for nftw*/
#include "utils.h"
#include <attr/xattr.h>			/*for extended attributes functions*/
#include <ftw.h> 						/*for recursive option*/
#include "optarg.h"
#include "format.h"

/*string to add to tag name for setxattr and removexattr*/
/*and to remove for listxattr, LU being its length*/
#define USER "user."
#define LU 5

/*for tag_list output*/
typedef struct tag
{
	char *name;		/*tag name*/
	int c;				/*count*/
} tag;

/*for tag_get output*/
typedef struct gettag
{
	char *file;					/*name of the file*/
	size_t n; 					/*number of tags*/
	char **list;				/*their name*/
	char *format;				/*their format*/
	R_TAG **values;			/*their values*/
} gettag;

/*tag_query*/
typedef struct qout
{
	int fc;
	char **file_list;
} qout;

/*tag_get*/
typedef struct gout
{
	int gc;
	gettag **tag_get;
} gout;

/*tag_list*/
typedef struct lout
{
	int tc;
	tag **taglist;
} lout;

void tagqtu(glob_optarg *glo, qout *out);
void tags(glob_optarg *glo);
void tagd(glob_optarg *glo);
void tagg(glob_optarg *glo, gout *out);
void tagl(glob_optarg *glo, lout *out);
void tag_save(glob_optarg *glo);
void tag_restore(glob_optarg *glo);

#endif
