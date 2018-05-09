#include "include/format.h"

static int is_integer(char *str, size_t l);
static int is_date(char *str, size_t l);
static int is_link(char *str, size_t l);

char check_format(char *attrval, size_t l)
{
	if(is_date(attrval, l))
		return DATE;
	else if(is_integer(attrval, l))
		return INT;
	else if(is_link(attrval, l))
		return LINK;
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

static int is_integer(char *str, size_t l)
{
	for(char *p = str; p < str+l; p++)
	{
		if(p == str && (*p == '-' || *p == '+'))
			continue;
		else if(!(*p > 47 && *p < 58))
			return 0;
	}

	return 1;
}

static int is_link(char *str, size_t l)
{
	int ret = 0;
	char *lnk = strncpy((char *)salloc(l+1), str, l);
	lnk[l] = '\0';
	ret = f_exists(lnk);
	free(lnk);
	return ret;
}

int int64ovf(char *val, size_t l)
{
	uint64_t limit = val[0] == '-' ? (uint64_t)(INT64_MAX)+1 : INT64_MAX;
	uint64_t inb = 0;
	uint64_t dec = 1;

	if(!(val[0] >= '0' && val[0] <= '9'))
	{
		val++;
		l--;
	}
	for(int i = (int)(l-1); i >= 0; i--)
	{
		inb += ((uint64_t)(val[i]-48))*dec;
		if(inb > limit || (limit/dec) == 0)
			return 1;
		dec *= 10;
	}

	return 0;
}

int check_date(int64_t y, int m, int d)
{
	int ret;

	if(m>=0 && m<=12)
	{
		if((d>=0 && d<=31)
			&& (m== 0 || m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12))
			ret = 0;
		else if((d>=0 && d<=30) && (m==4 || m==6 || m==9 || m==11))
			ret = 0;
		else if((d>=0 && d<=28) && (m==2))
			ret = 0;
		else if(d==29 && m==2 && (y%400==0 ||(y%4==0 && y%100!=0)))
			ret = 0;
		else
			ret = 3;
	}
	else
		ret = 2;

	return ret;
}
