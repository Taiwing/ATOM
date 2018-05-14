#ifndef LIBTAG_H
#define LIBTAG_H

#include "tag.h"

qout *tag_query(char *query, int flags, char **files, int fc);
gout *tag_get(int flags, char **files, int fc);
lout *tag_list(int flags, char **files, int fc);
void tag_set(char *name, char *value, int flags, char **files, int fc);
void tag_delete(char *name, int flags, char **files, int fc);

#endif
