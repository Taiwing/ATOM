#ifndef FORMAT_H
#define FORMAT_H
#include <sys/types.h>			/*for the size_t type*/
#include <inttypes.h>				/*for fixed length integers*/
#include "read_write.h"

/*TODO:*/
/*retag every tagged file with the new tag format*/
/*by writing a little script to update every tag value*/
/*by detecting the format and appending the corresponding*/
/*character at the begining of the value string*/

char check_format(char *attrval, size_t l);

#endif
