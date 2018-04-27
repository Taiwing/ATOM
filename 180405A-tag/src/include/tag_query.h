/*is the header of tag_query.c query_checker.c build_qtree.c match.c*/
#ifndef TAG_QUERY_H
#define TAG_QUERY_H
#include "tag.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>			/*for the size_t type*/

enum QUERY_CHARS {
	AND = '&',
	OR = '|',
	XOR = '^',
	NOT = '!',
	LPAR = '(',
	RPAR = ')',
	ANT = '\\'
};

extern char *ro_str[];

enum REL_OPS {EQ = 1, NEQ, GEQ, LEQ, GT, LT};

typedef struct query_node
{
	int log_op;	/*AND OR XOR NOT 0*/
	int rel_op;	/*EQ, NEQ, GT, LT, GEQ, LEQ 0*/
	/*dt will store the name of the attribute*/
	/*to be tested, if node is a leaf and rel_op == 0*/
	tag_val *dt[2];	/*only the first one is used if rel_op == 0*/
	char dt_type[2];	/*stores the type of value in dt*/
	struct query_node *left;	/*next lighter node*/
	struct query_node *right;	/*next heavier node*/
} query_node;

/*tests if the query is valid*/
int valid_query(char *query);

/*if it is, this one builds the structre for it*/
query_node *build_qtree(char *query, size_t n);

/*recursively traverse the tree and tests each node*/
int test_node(query_node *nd, char *l, size_t n, const char *file);

#endif
