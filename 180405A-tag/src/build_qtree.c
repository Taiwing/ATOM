#include "include/tag_query.h"

static int weight(char **expr, size_t *n);
static int get_log_op(char *query, size_t n, char **p, size_t *j);
static int get_rel_op(char *query, size_t n, char **r);
static void def_rel_val(query_node *nd, char *query, size_t n, char *r);
static date_s *read_date(char *str, size_t l);

/*if it is, this one builds the structure for it*/
query_node *build_qtree(char *query, size_t n)
{
	query_node *nd = (query_node *)salloc(sizeof(query_node));
	char *p = NULL; /*next node*/
	size_t j = 0;
	nd->log_op = get_log_op(query, n, &p, &j);

	if(nd->log_op && nd->log_op != NOT)
	{
		size_t k = n-(j+1);
		int lef = weight(&query, &j);
		int rig = weight(&p, &k);
		nd->left = lef <= rig ? build_qtree(query, j) : build_qtree(p, k);
		nd->right = lef <= rig ? build_qtree(p, k) : build_qtree(query, j);
	}
	else if(nd->log_op == NOT)
	{
		size_t k = n-(j+1);
		weight(&p, &k);
		nd->left = build_qtree(p, k);
	}
	else if(nd->log_op == 0)
	{
		char *r = NULL;
		nd->rel_op = get_rel_op(query, n, &r);
		if(nd->rel_op == 0)
		{
			nd->dt[0] = (tag_val*)salloc(sizeof(tag_val));
			nd->dt[0]->attr = strcpy((char *)salloc(n+LU+1), USER);
			strncat(nd->dt[0]->attr, query, n);
			rmbs(nd->dt[0]->attr, n+LU);
		}
		else
			def_rel_val(nd, query, n, r);
	}

	return nd;
}

static int weight(char **expr, size_t *n)
{
	if(*expr[0] == LPAR) /*remove parenthesis*/
	{
		*expr = (*expr)+1; /*should be equivalent to (*expr)++*/
		(*n) -= 2;
	}

	int w = 0;

	for(char *p = *expr; p < (*expr)+(*n); p++)
		switch(*p)
		{
			case AND:
			case OR:
			case XOR:
			case NOT:
			case LPAR: w++;
				break;
			case ANT: p++;
				break;
		}

	return w;
}

static int get_log_op(char *query, size_t n, char **p, size_t *j)
{
	int log_op = 0, par = 0;

	for(size_t i = 0; i < n && (log_op == 0 || log_op == NOT); i++)
		switch(query[i])
		{
			case LPAR: par++;
				break;
			case RPAR: par--;
				break;
			case AND:
			case OR:
			case XOR:
			case NOT:
				if(!par && (query[i] != NOT || query[i+1] != '='))
				{
					log_op = query[i];
					*p = query+i+1;
					*j = i;
				}
				break;
			case ANT: i++;
				break;
		}

	return log_op;
}

static int get_rel_op(char *query, size_t n, char **r)
{
	int rel_op = 0;
	char *q = strncpy((char *)salloc(n+1), query, n);
	q[n] = '\0';
	for(int i = 1; i < 7; i++)
	{
		*r = strstr(q, ro_str[i]);
		if(*r && *((*r)-1) != '\\')
		{
			*r = &(query[(*r)-q]);
			rel_op = i;
			break;
		}
		else
			*r = NULL;
	}
	free(q);
	return rel_op;
}

static void def_rel_val(query_node *nd, char *query, size_t n, char *r)
{
	size_t l[2]; /*string length (not counting null_byte)*/
	char *relelm[2] = {query, &(r[strlen(ro_str[nd->rel_op])])};
	l[0] = r-query; /*lengh of left string*/
	l[1] = n-l[0]-strlen(ro_str[nd->rel_op]); /*length of right string*/
	for(int i = 0; i < 2; i++)
	{
		nd->dt[i] = (tag_val*)salloc(sizeof(tag_val));
		nd->dt[i]->val = (R_TAG *)salloc(sizeof(R_TAG));
	}

	for(int i = 0; i < 2; i++)
	{
		if(is_quoted(relelm[i], l[i])) /*if one of them is quoted*/
		{
			/*revmove quotes from char count*/
			l[i] -= 2;
			relelm[i]++;
			nd->dt[i]->type = check_format(relelm[i], l[i]);

			/*then it is the value*/
			if(nd->dt[i]->type == INT)
				nd->dt[i]->val->inb = (int64_t)atoi(relelm[i]);
			else if(nd->dt[i]->type == STR)
			{
				nd->dt[i]->val->str = (uint8_t *)salloc(l[i]+1);
				strncpy((char *)(nd->dt[i]->val->str), relelm[i], l[i]);
				nd->dt[i]->val->str[l[i]] = '\0';
				rmbs((char *)(nd->dt[i]->val->str), l[i]);
			}
			else if(nd->dt[i]->type == DATE)
				nd->dt[i]->val->date = read_date(relelm[i], l[i]);

			/*and the other is the attribute*/
			nd->dt[!i]->attr = strcpy((char *)salloc(l[!i]+LU+1), USER);
			strncat(nd->dt[!i]->attr, relelm[!i], l[!i]);
			rmbs(nd->dt[!i]->attr, l[!i]+LU);
			nd->dt[!i]->type = ATTR;
			return;
		}
	}

	/*if none of them is quoted*/
	for(int i = 0; i < 2; i++)
	{
		nd->dt[i]->type = check_format(relelm[i], l[i]);
		if(nd->dt[i]->type != STR) /*if one of them is formatted*/
		{
			/*then it is the value*/
			if(nd->dt[i]->type == INT)
				nd->dt[i]->val->inb = (int64_t)atoi(relelm[i]);
			else if(nd->dt[i]->type == DATE)
				nd->dt[i]->val->date = read_date(relelm[i], l[i]);

			/*and the other is the attribute*/
			nd->dt[!i]->attr = strcpy((char *)salloc(l[!i]+LU+1), USER);
			strncat(nd->dt[!i]->attr, relelm[!i], l[!i]);
			rmbs(nd->dt[!i]->attr, l[!i]+LU);
			nd->dt[!i]->type = ATTR;
			return;
		}
	}

	/*both of them are tag names*/
	for(int i = 0; i < 2; i++)
	{
		nd->dt[i]->attr = strcpy((char *)salloc(l[i]+LU+1), USER);
		strncat(nd->dt[i]->attr, relelm[i], l[i]);
		nd->dt[i]->type = ATTR;
	}
}

static date_s *read_date(char *str, size_t l)
{
	date_s *date = (date_s *)salloc(sizeof(date_s));
	int hc = 0; 	/*hyphen count*/
	int dc = 1; 	/*decimal count*/

	date->year = 0;
	date->month = 0;
	date->day = 0;

	for(char *p = str+l-1; p >= str; p--)
	{
		if(hc < 2 && *p == '-')
		{
			dc = 1;
			hc++;
		}
		else
		{
			if(hc == 0)
				date->day += (uint8_t)(((*p)-48)*dc);
			else if(hc == 1)
				date->month += (uint8_t)(((*p)-48)*dc);
			else if(hc == 2 && *p >= '0' && *p <= '9')
				date->year += (int64_t)(((*p)-48)*dc);
			else if(hc == 2 && *p == '-')
				date->year *= -1;

			dc *= 10;
		}
	}

	return date;
}
