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
			val->date = (date_s *)salloc(sizeof(date_s));
			val->date->day = ((uint8_t *)raw_val)[1];
			val->date->month = ((uint8_t *)raw_val)[2];
			val->date->year = *((int64_t *)(&(((uint8_t *)raw_val)[3])));
			break;
	}

	return format;
}

void *write_value(char *valstring, size_t *vallen, char format)
{
	switch(format)
	{
		case STR:
			*vallen = strlen(valstring)+2;
			W_TAG_STR str = salloc(*vallen);
			str[0] = format;
			strcpy((char *)str+1, valstring);
			return (void *)str;
			break;
		case NB:
			*vallen = sizeof(W_TAG_INT);
			W_TAG_INT *nb = (W_TAG_INT *)salloc(sizeof(W_TAG_INT));
			nb->f_int[0] = format;
			*((int64_t *)(&(nb->f_int[1]))) = (int64_t)atoi(valstring);
			return (void *)(nb);
			break;
		case DATE:
			*vallen = sizeof(W_TAG_DATE);
			W_TAG_DATE *dt = (W_TAG_DATE *)salloc(sizeof(W_TAG_DATE));
			dt->f_d_m_y[0] = format;
			fetch_date(valstring, dt);
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

	for(int i = 1; i < 11; i++)
		dt->f_d_m_y[i] = 0;

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
				dt->f_d_m_y[1] += (uint8_t)(((*p)-48)*dc);
			else if(hc == 1)
				dt->f_d_m_y[2] += (uint8_t)(((*p)-48)*dc);
			else if(hc == 2 && *p >= '0' && *p <= '9')
				*((int64_t *)(&(dt->f_d_m_y[3]))) += (int64_t)(((*p)-48)*dc);
			else if(hc == 2 && *p == '-')
				*((int64_t *)(&(dt->f_d_m_y[3]))) *= -1;

			dc *= 10;
		}
	}
}
