#ifndef TAG_QUERY_H
#define TAG_QUERY_H
#include "tag.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>			/*for the size_t type*/

#define Q_CHARS "&|^!()\\"

enum QUERY_CHARS {
	AND = '&',
	OR = '|',
	XOR = '^',
	NOT = '!',
	LPAR = '(',
	RPAR = ')',
	ANT = '\\'
};

typedef struct query_node
{
	int log_op;	/*AND OR XOR NOT*/
	char *attr;	/*name of the attribute to be tested, if node is a leaf*/
	struct query_node *left;	/*next lighter node*/
	struct query_node *right;	/*next heavier node*/
} query_node;

/*tests if the query is valid*/
int valid_query(char *query);

/*if it is, this one builds the structre for it*/
query_node *build_qtree(char *query, size_t n);

/*recursively traverse the tree and tests each node*/
int test_node(query_node *nd, char *l, size_t n);

#endif
