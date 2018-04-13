#include "tag_query.h"

static int weight(char **expr, size_t *n);

/*tests if the query is valid*/
int valid_query(char *query);

/*if it is, this one builds the structure for it*/
query_node *build_qtree(char *query, size_t n)
{
	query_node *nd = (query_node *)malloc(sizeof(query_node));
	nd->log_op = 0;

	int par = 0;
	size_t j = 0;
	char *p; /*next node*/

	for(size_t i = 0; i < n && (nd->log_op == 0 || nd->log_op == NOT); i++)
	{
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
		}
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
		nd->attr = strcpy((char *)malloc(n+LU+1), USER);
		strncat(nd->attr, query, n);
	}

	return nd;
}

int test_node(query_node *nd, char *l, size_t n)
{
	int ret = 0;
	char *p;
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
			for(p = l; p < l+n; p += strlen(p)+1)
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
			case LPAR:
				w++;
				break;
		}

	return w;
}
