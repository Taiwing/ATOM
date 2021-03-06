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

void tagqtu(glob_optarg *glo);
void tags(glob_optarg *glo);
void tagd(glob_optarg *glo);
void tagg(glob_optarg *glo);
void tagl(glob_optarg *glo);
void tag_save(glob_optarg *glo);
void tag_restore(glob_optarg *glo);

#endif
