#include "include/tag_query.h"

/*TODO*/
/*First: test that everything is working as expected*/
/*Dos: Make some functions shorter*/
/*Tres: maybe divide this file into multiple files*/

char *ro_str[] = {
	"",
	"==",
	"!=",
	">=",
	"<=",
	">",
	"<",
};

static int weight(char **expr, size_t *n);
static int get_log_op(char *query, size_t n, char **p, size_t *j);
static int get_rel_op(char *query, size_t n, char **r);
static void def_rel_val(query_node *nd, char *query, size_t n, char *r);
static int do_log_op(query_node *nd, char *l, size_t n, const char *f);
static int do_rel_op(query_node *nd, const char *f);
static int dt_type_match(query_node *nd, int i, const char *f, void *val[2]);

/*tests if the query is valid*/
int valid_query(char *query)
{
	int err = 0;
	int rpar = 0, lpar = 0, nest = 0, l = strlen(query);
	int *parray = (int *)salloc(l * sizeof(int));
	for(int i = 0; i < l; i++)
	{
		if(query[i] == LPAR)
			lpar++;
		nest = lpar - rpar;
		switch(query[i])
		{
			case LPAR:
			case RPAR: parray[i] = nest;
					break;
			case AND:
			case OR:
			case XOR: parray[i] = -2;
					break;
			case NOT: parray[i] = -1;
					break;
			case ANT: parray[i] = 0;
				if(i < l-1)
					parray[++i] = 0;
				else
				 	err = 1;
				break;
			default:  parray[i] = 0;
					break;
		}
		if(query[i] == RPAR)
			rpar++;
		if(lpar - rpar < 0) /*if there's more RPAR than LPAR*/
			err = 1;
	}

	if(lpar != rpar) /*if there's not the same total of LPAR and RPAR*/
		err = 1;

	for(int i = 0; i < l; i++) /*rules regarding character placement*/
	{
		switch(parray[i])
		{
			case -2:
				if(i == 0 || i == l-1
					|| (query[i-1] == '(' && parray[i-1] != 0)
					|| query[i+1] == ')'
					|| parray[i+1] == -2)
					err = 1;
				break;
			case -1:
				if(i == l-1 || query[i+1] == ')' || parray[i+1] == -2)
					err = 1;
				break;
			case 0:
				if((i != 0 && query[i-1] == ')' && parray[i-1] != 0)
					|| (i != l-1 && query[i+1] == '('))
					err = 1;
				break;
		}
	}
	free(parray);

	if(err)
	{
		fprintf(stderr, "%s: incorrect query\n", PROGNAME);
		exit(EXIT_FAILURE);
	}
	else
		return 1;
}

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
			nd->dt[0] = (tag_val *)salloc(sizeof(tag_val));
			nd->dt[0]->attr = strcpy((char *)salloc(n+LU+1), USER);
			strncat(nd->dt[0]->attr, query, n);
			rmbs(nd->dt[0]->attr, n+LU);
		}
		else
			def_rel_val(nd, query, n, r);
	}

	return nd;
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
	nd->dt[0] = (tag_val *)salloc(sizeof(tag_val));
	nd->dt[1] = (tag_val *)salloc(sizeof(tag_val));

	for(int i = 0; i < 2; i++)
	{
		if(is_quoted(relelm[i], l[i])) /*if one of them is quoted*/
		{
			/*revmove quotes from char count*/
			l[i] -= 2;
			relelm[i]++;

			/*then it is the value*/
			if(is_numeric(relelm[i], l[i]))
			{
				nd->dt[i]->nb = atof(relelm[i]);
				nd->dt_type[i] = NB;
			}
			else
			{
				nd->dt[i]->str = strncpy((char *)salloc(l[i]+1), relelm[i], l[i]);
				nd->dt[i]->str[l[i]] = '\0';
				rmbs(nd->dt[i]->str, l[i]);
				nd->dt_type[i] = STR;
			}

			/*and the other is the attribute*/
			nd->dt[!i]->attr = strcpy((char *)salloc(l[!i]+LU+1), USER);
			strncat(nd->dt[!i]->attr, relelm[!i], l[!i]);
			rmbs(nd->dt[!i]->attr, l[!i]+LU);
			nd->dt_type[!i] = ATTR;
			return;
		}
	}

	/*if none of them is quoted*/
	for(int i = 0; i < 2; i++)
	{
		if(is_numeric(relelm[i], l[i])) /*if one of them is a numerical string*/
		{
			/*then it is the value*/
			nd->dt[i]->nb = atof(relelm[i]);
			nd->dt_type[i] = NB;

			/*and the other is the attribute*/
			nd->dt[!i]->attr = strcpy((char *)salloc(l[!i]+LU+1), USER);
			strncat(nd->dt[!i]->attr, relelm[!i], l[!i]);
			rmbs(nd->dt[!i]->attr, l[!i]+LU);
			nd->dt_type[!i] = ATTR;
			return;
		}
	}

	/*both of them are tag names*/
	for(int i = 0; i < 2; i++)
	{
		nd->dt[i]->attr = strcpy((char *)salloc(l[i]+LU+1), USER);
		strncat(nd->dt[i]->attr, relelm[i], l[i]);
		nd->dt_type[i] = ATTR;
	}
}

int test_node(query_node *nd, char *l, size_t n, const char *file)
{
	if(nd->log_op)
		return do_log_op(nd, l, n, file);
	else if(nd->rel_op)
		return do_rel_op(nd, file);
	else
		for(char *p = l; p < l+n; p += strlen(p)+1)
			if(strcmp(nd->dt[0]->attr, p) == 0)
				return 1;
	return 0;
}

static int do_log_op(query_node *nd, char *l, size_t n, const char *f)
{
	switch(nd->log_op)
	{
		case AND:
			return (test_node(nd->left, l, n, f) && test_node(nd->right, l, n, f));
			break;
		case OR:
			return (test_node(nd->left, l, n, f) || test_node(nd->right, l, n, f));
			break;
		case XOR:
			return (test_node(nd->left, l, n, f) ^ test_node(nd->right, l, n, f));
			break;
		case NOT:
			return (!test_node(nd->left, l, n, f));
			break;
	}

	return 0; /*not possible*/
}

static int do_rel_op(query_node *nd, const char *f)
{
	int ret = 0, i, type;
	void *val[2];

	/*get the type of data to be compared*/
	for(i = 0; i < 2 && nd->dt_type[i] == ATTR; i++);

	/*if the same type of data is being compared, and is valid*/
	if((type = dt_type_match(nd, i, f, val)))
	{
		double nb_val[2];
		char *str_val[2];
		if(i < 2)
			for(int j = 0; j < 2; j++)
			{
				if(type == NB)
					nb_val[j] = j == i ? nd->dt[j]->nb : *((double *)val[j]);
				else
					str_val[j] = j == i ? nd->dt[j]->str : (char *)val[j];
			}
		else
			for(int j = 0; j < 2; j++)
			{
				if(type == NB)
					nb_val[j] =  *((double *)val[j]);
				else
					str_val[j] = (char *)val[j];
			}
		switch(nd->rel_op)
		{
			case EQ:
				ret = type == NB ? (nb_val[0] == nb_val[1])
						: (strcmp(str_val[0], str_val[1]) == 0);
				break;
			case NEQ:
				ret = type == NB ? (nb_val[0] != nb_val[1])
						: (strcmp(str_val[0], str_val[1]) != 0);
				break;
			case GEQ:
				ret = type == NB ? (nb_val[0] >= nb_val[1])
						: (strcmp(str_val[0], str_val[1]) >= 0);
			break;
			case LEQ:
				ret = type == NB ? (nb_val[0] <= nb_val[1])
						: (strcmp(str_val[0], str_val[1]) <= 0);
				break;
			case GT:
				ret = type == NB ? (nb_val[0] > nb_val[1])
						: (strcmp(str_val[0], str_val[1]) > 0);
				break;
			case LT:
				ret = type == NB ? (nb_val[0] < nb_val[1])
						: (strcmp(str_val[0], str_val[1]) < 0);
				break;
		}

		if(type == STR) /*clean buffer for next test*/
		{
			if(i < 2)
				memset((void *)(str_val[!i]), 0, strlen(str_val[!i]));
			else
				for(int j = 0; j < 2; j++)
					memset((void *)(str_val[j]), 0, strlen(str_val[j]));
		}
	}

	if(i < 2 && type)
		free(val[!i]);
	else if(type)
		for(int j = 0; j < 2; j++)
			free(val[j]);

	return ret;
}

static int dt_type_match(query_node *nd, int i, const char *f, void *val[2])
{
	int ret = 0;
	char *v[2];
	double *nb[2];
	ssize_t l[2];

	v[0] = (char *)salloc(XATTR_SIZE_MAX);
	v[1] = (char *)salloc(XATTR_SIZE_MAX);

	if(i < 2) /*if one of them is a literal value*/
	{
		switch(nd->dt_type[i]) /*check if the other is of the same type*/
		{
			case STR:
				if((l[!i] = getxattr(f, nd->dt[!i]->attr, v[!i], XATTR_SIZE_MAX)) > 0)
				{
					ret = STR;
					val[!i] = (void *)v[!i];
				}
				break;
			case NB:
				if((l[!i] = getxattr(f, nd->dt[!i]->attr, v[!i], XATTR_SIZE_MAX)) > 0
					 && is_numeric(v[!i], l[!i]))
				{
					ret = NB;
					nb[!i] = (double *)salloc(sizeof(double));
					*(nb[!i]) = atof(v[!i]);
					val[!i] = (void *)nb[!i];
				}
				break;
		}
	}
	else
	{
		if((l[0] = getxattr(f, nd->dt[0]->attr, v[0], XATTR_SIZE_MAX)) > 0
			 && (l[1] = getxattr(f, nd->dt[0]->attr, v[0], XATTR_SIZE_MAX)) > 0)
		{
			if(is_numeric(v[0], l[0]) && is_numeric(v[1], l[1]))
			{
				ret = NB;
				for(int j = 0; j < 2; j++)
				{
					nb[j] = (double *)salloc(sizeof(double));
					*(nb[j]) = atof(v[j]);
					val[j] = (void *)nb[j];
				}
			}
			else
			{
				ret = STR;
				val[0] = (void *)v[0];
				val[1] = (void *)v[1];
			}
		}
	}

	if(ret == 0 || ret == NB)
		for(int j = 0; j < 2; j++)
			free(v[j]);
	else if(i < 2)
		free(v[i]);

	return ret;
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
