#ifndef FORMAT_H
#define FORMAT_H
#include <sys/types.h>			/*for the size_t type*/
#include <inttypes.h>				/*for fixed length integers*/
#include "read_write.h"

char check_format(char *attrval, size_t l);

#endif
