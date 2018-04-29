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
/*add W_XX_VAL structures for efficient writing on the drive*/
/*the structures must use fixed-length variables from stdint.h*/
/*to be the same size on every implementation (so tags can be read*/
/*easely from one computer to the next, without having to convert anything)*/
/*and they must all begin with a format byte*/

/*format structures*/
typedef struct date
{
	int y;		/*Year*/
	char m;		/*Month*/
	char d;		/*Day*/
} date;

/*stores the value of a tag in a query (tag_query.h)*/
typedef union tag_val
{
	char *attr;	/*if a tag_value is being compared*/
	char *str;	/*if it is a string*/
	double nb;	/*if it is a number*/
	date *dt;		/*if it is a date*/
} tag_val;

char check_format(char *attrval, size_t l);

#endif
