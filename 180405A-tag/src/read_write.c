#include "include/read_write.h"

static void fetch_date(char *datestring, W_TAG_DATE *dt);

/*returns the format if the read data*/
uint8_t read_value(void *raw_val, size_t size, R_TAG *val)
{
	uint8_t format = *((uint8_t *)raw_val); /*format byte*/

	switch(format)
	{
		case STR: /*string*/
			val->str = (uint8_t *)salloc((size-1) * sizeof(uint8_t));
			for(size_t i = 0; i < size-1; i++)
				val->str[i] = ((uint8_t *)raw_val)[i+1];
			break;
		case NB: /*number*/
			for(int i = 0; i < 8; i++)
				((uint8_t *)&(val->nb))[i] = ((uint8_t *)raw_val)[i+1];
			break;
		case DATE: /*date*/
			val->date = (struct date_s *)salloc(sizeof(struct date_s));
			for(int i = 0; i < 6; i++)
				((uint8_t *)&(val->date->year))[i] = ((uint8_t *)raw_val)[i+1];
			((uint8_t *)&(val->date->year))[6] = ((uint8_t *)raw_val)[7] & 127;
			((uint8_t *)&(val->date->year))[7] = ((uint8_t *)raw_val)[7] & 128;
			val->date->month = ((uint8_t *)raw_val)[8];
			val->date->day = ((uint8_t *)raw_val)[9];
			break;
	}

	return format;
}

void *write_value(char *valstring, size_t *vallen, char format)
{
	switch(format)
	{
		case 'S':
			*vallen = strlen(valstring)+2;
			W_TAG_STR str = salloc(*vallen);
			str[0] = format;
			strcpy((char *)str+1, valstring);
			return (void *)str;
			break;
		case 'N':
			*vallen = sizeof(W_TAG_INT);
			W_TAG_INT *nb = (W_TAG_INT *)salloc(sizeof(W_TAG_INT));
			nb->f_int[0] = format;
			*((uint64_t *)((&nb)+1)) = (uint64_t)atoi(valstring);
			return (void *)(nb);
			break;
		case 'D':
			*vallen = sizeof(W_TAG_DATE);
			W_TAG_DATE *dt = (W_TAG_DATE *)salloc(sizeof(W_TAG_DATE));
			dt->f_year[0] = format;
			fetch_date(valstring+1, dt);
			return (void *)(dt);
			break;
	}
	return NULL;
}

static void fetch_date(char *datestring, W_TAG_DATE *dt)
{
	size_t l = strlen(datestring);
	int hc = 0; 	/*hyphen count*/
	int dc = 1; 	/*decimal count*/
	uint8_t sign = 127;
	uint64_t year = 0;

	for(int i = 1; i < 8; i++)
		dt->f_year[i] = 0;
	for(int i = 0; i < 2; i++)
		dt->month_day[i] = 0;

	for(char *p = datestring+l-1; p >= datestring; p--)
	{
		if(hc < 2 && *p == '-')
		{
			dc = 1;
			hc++;
		}
		else
		{
			if(hc == 0)
				dt->month_day[1] += (uint8_t)(((*p)-48)*dc);
			else if(hc == 1)
				dt->month_day[0] += (uint8_t)(((*p)-48)*dc);
			else if(hc == 2 && *p >= '0' && *p <= '9')
				year += (uint64_t)(((*p)-48)*dc);
			else if(hc == 2 && *p == '-')
				sign += 128;

			dc *= 10;
		}
	}

	for(int i = 7; i > 0; i--)
		dt->f_year[i] = ((uint8_t *)year)[i];

	dt->f_year[7] &= sign;
}
