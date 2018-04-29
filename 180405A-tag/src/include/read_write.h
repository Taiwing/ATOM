/*wite.h defines the data structures that*/
/*will be written as tag values on the disk*/
#ifndef READ_WRITE_H
#define READ_WRITE_H
#include <stdint.h>	/*for fixed-width integers*/
#include "utils.h"

/*tag values formats*/
/*ATTR means no format specified (useful in match.c)*/
/*aside from ATTR, each format is attributed a character*/
/*which will be appended at the begining of every tag value*/
enum format {
	ATTR = 0,
	STR = 'S',
	NB = 'N',
	DATE = 'D'
};

/*format and data are not seperated to avoid alignment padding*/

typedef uint8_t* W_TAG_STR; /*is always one byte longer than value string*/

typedef struct W_TAG_INT
{
	uint8_t f_int[9];	/*format byte and a 64bits little-endian int*/
} W_TAG_INT;

typedef struct W_TAG_DATE
{
	uint8_t f_year[8];		/*format byte, and a 7byte int for the year*/
	uint8_t month_day[2];	/*first byte is the month, and second is the day*/
} W_TAG_DATE;

/*the year being a seven bytes intger*/
/*max absolute value = 2^55-1 = 36.028.797.020.000.000*/
typedef union R_TAG	/*TODO: replace tag_val (nd->dt) by this*/
{
	uint8_t *str;
	int64_t nb;
	struct date_s
	{
		int64_t year;
		uint8_t month;
		uint8_t day;
	} *date;
} R_TAG;

uint8_t read_value(void *raw_val, size_t size, R_TAG *val);
void *write_value(char *valstring, size_t *vallen, char format);

#endif
