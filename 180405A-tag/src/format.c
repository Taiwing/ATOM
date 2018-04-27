#include "include/format.h"

static int is_numeric(char *str, size_t l);
static int is_date(char *str, size_t l);

char check_format(char *attrval, size_t l)
{
	if(is_date(attrval, l))
		return DATE;
	else if(is_numeric(attrval, l))
		return NB;
	else
		return STR;
}

static int is_date(char *str, size_t l)
{
	int hc = 0; /*hyphen count*/
	int dc = 0; /*digits count*/

	for(char *p = str; p < str+l; p++)
	{
		if(p == str && (*p == '-' || *p == '+'))
			continue;
		else if(*p != '-')
		{
			if(!(*p >= '0' && *p <= '9') || (hc > 0 && dc == 2))
				break;
			dc++;
		}
		else if(*p == '-')
		{
			if(dc == 0 || (hc > 0 && dc != 2))
				break;
			dc = 0;
			hc++;
		}
		if(p == str+l-1 && hc == 2 && dc == 2)
			return 1;
	}

	return 0;
}

static int is_numeric(char *str, size_t l)
{
	int pc = 0; /*point count*/

	for(char *p = str; p < str+l; p++)
	{
		if(p == str && (*p == '-' || *p == '+'))
			continue;
		else if(!((*p > 47 && *p < 58) || (*p == '.' && pc < 1)))
			return 0;
		else if(*p == '.')
			pc++;
	}

	return 1;
}
