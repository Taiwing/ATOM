#include "include/tag_query.h"

static int weight(char **expr, size_t *n);

/*tests if the query is valid*/
int valid_query(char *query)
{
	int err = 0;
	int rpar = 0, lpar = 0, nest = 0, l = strlen(query);
	int *parray = (int *)smalloc(l * sizeof(int));
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
	query_node *nd = (query_node *)smalloc(sizeof(query_node));
	nd->log_op = 0;

	int par = 0;
	size_t j = 0;
	char *p; /*next node*/

	for(size_t i = 0; i < n && (nd->log_op == 0 || nd->log_op == NOT); i++)
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
				if(!par)
				{
					nd->log_op = query[i];
					p = query+i+1;
					j = i;
				}
				break;
			case ANT: i++;
				break;
		}

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
		nd->attr = strcpy((char *)smalloc(n+LU+1), USER);
		strncat(nd->attr, query, n);
		for(char *cp = nd->attr+LU; cp < nd->attr+n; cp++)
		{
			if(*cp == '\\')
			{
				backspace(nd->attr, sizeof(char), n+LU+1, cp-nd->attr, 1);
				p++;
			}
		}
	}

	return nd;
}

int test_node(query_node *nd, char *l, size_t n)
{
	int ret = 0;
	switch(nd->log_op)
	{
		case AND:
			if(test_node(nd->left, l, n) && test_node(nd->right, l, n))
				ret = 1;
			break;
		case OR:
			if(test_node(nd->left, l, n) || test_node(nd->right, l, n))
				ret = 1;
			break;
		case XOR:
			if(test_node(nd->left, l, n) ^ test_node(nd->right, l, n))
				ret = 1;
			break;
		case NOT:
			if(!test_node(nd->left, l, n))
				ret = 1;
			break;
		case 0:
			for(char *p = l; p < l+n; p += strlen(p)+1)
				if(strcmp(nd->attr, p) == 0)
				{
					ret = 1;
					break;
				}
			break;
	}
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
