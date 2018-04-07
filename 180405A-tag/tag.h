#ifndef TAG_H
#define TAG_H

#define _XOPEN_SOURCE 500 	/*required for nftw*/
#include "utils.h"
#include <attr/xattr.h>			/*for extended attributes functions*/
#include <ftw.h> 						/*for recursive option*/
#include "optarg.h"

void tags(glob_optarg *glo);
void tagd(glob_optarg *glo);
void tagl(glob_optarg *glo);

#endif
