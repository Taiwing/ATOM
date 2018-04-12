#include "match.h"

/*tests if the query is valid*/
int valid_query(char *query);

/*if it is, this one builds the structre for it*/
query_node *build_qtree(char *query);

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
				int lef = test_node(nd->left, l, n);
				int rig = test_node(nd->right, l, n);
				if(lef ^ rig)
					ret = 1;
			break;
		case NOT:
			break;
		case 0:
			break;
	}
	char *p;
	for(p = l; p < ls+n; p += strlen(p)+1);
}
