#include "include/tag_query.h"

static int do_log_op(query_node *nd, char *l, size_t n, const char *f);
static int do_rel_op(query_node *nd, const char *f);
static int dt_type_match(query_node *nd, int i, const char *f, void *val[2]);

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
	ssize_t l[2]; /*ssize_t because getxattr can return -1*/

	for(int j = 0; j < 2; j++) /*clean the buffers beforehand*/
	{
		v[j] = (char *)salloc(XATTR_SIZE_MAX);
		memset((void *)v[j], 0, XATTR_SIZE_MAX);
	}

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
