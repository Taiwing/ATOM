#include "include/tag_query.h"

static int do_log_op(query_node *nd, char *l, size_t n, const char *f);
static int do_rel_op(query_node *nd, const char *f);
static uint8_t dt_type_match(query_node *nd, int i, const char *f);
static int64_t dacmp(date_s *date1, date_s *date2, uint8_t flags);
static int16_t ustrcmp(uint8_t *str1, uint8_t *str2);

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
	int ret = 0, i;
	uint8_t type;

	/*get the type of data to be compared*/
	for(i = 0; i < 2 && nd->dt[i]->type == ATTR; i++);

	/*if the same type of data is being compared, and is valid*/
	if((type = dt_type_match(nd, i, f)))
	{
		switch(nd->rel_op)
		{
			case EQ:
				ret = type == INT ?
						(nd->dt[0]->val->inb == nd->dt[1]->val->inb)
						: type == STR ?
						(ustrcmp(nd->dt[0]->val->str, nd->dt[1]->val->str) == 0)
						: type == DATE ?
						(dacmp(nd->dt[0]->val->date, nd->dt[1]->val->date, 7) == 0)
						: 0;
				break;
			case NEQ:
				ret = type == INT ?
						(nd->dt[0]->val->inb != nd->dt[1]->val->inb)
						: type == STR ?
						(ustrcmp(nd->dt[0]->val->str, nd->dt[1]->val->str) != 0)
						: type == DATE ?
						(dacmp(nd->dt[0]->val->date, nd->dt[1]->val->date, 7) != 0)
						: 0;
				break;
			case GEQ:
				ret = type == INT ?
						(nd->dt[0]->val->inb >= nd->dt[1]->val->inb)
						: type == STR ?
						(ustrcmp(nd->dt[0]->val->str, nd->dt[1]->val->str) >= 0)
						: type == DATE ?
						(dacmp(nd->dt[0]->val->date, nd->dt[1]->val->date, 7) >= 0)
						: 0;
			break;
			case LEQ:
				ret = type == INT ?
						(nd->dt[0]->val->inb <= nd->dt[1]->val->inb)
						: type == STR ?
						(ustrcmp(nd->dt[0]->val->str, nd->dt[1]->val->str) <= 0)
						: type == DATE ?
						(dacmp(nd->dt[0]->val->date, nd->dt[1]->val->date, 7) <= 0)
						: 0;
				break;
			case GT:
				ret = type == INT ?
						(nd->dt[0]->val->inb > nd->dt[1]->val->inb)
						: type == STR ?
						(ustrcmp(nd->dt[0]->val->str, nd->dt[1]->val->str) > 0)
						: type == DATE ?
						(dacmp(nd->dt[0]->val->date, nd->dt[1]->val->date, 7) > 0)
						: 0;
				break;
			case LT:
				ret = type == INT ?
						(nd->dt[0]->val->inb < nd->dt[1]->val->inb)
						: type == STR ?
						(ustrcmp(nd->dt[0]->val->str, nd->dt[1]->val->str) < 0)
						: type == DATE ?
						(dacmp(nd->dt[0]->val->date, nd->dt[1]->val->date, 7) < 0)
						: 0;
				break;
		}
	}

	switch(type)
	{
		case STR:
			if(i < 2)
				free(nd->dt[!i]->val->str);
			else
				for(int j = 0; j < 2; j++)
					free(nd->dt[j]->val->str);
			break;
		case DATE:
			if(i < 2)
				free(nd->dt[!i]->val->date);
			else
				for(int j = 0; j < 2; j++)
					free(nd->dt[j]->val->date);
			break;
	}

	return ret;
}

static uint8_t dt_type_match(query_node *nd, int i, const char *f)
{
	uint8_t ret = 0;
	uint8_t *v[2];
	ssize_t l[2]; /*ssize_t because getxattr can return -1*/

	for(int j = 0; j < 2; j++) /*allocate and clean the buffers beforehand*/
	{
		v[j] = (uint8_t *)salloc(XATTR_SIZE_MAX);
		memset((void *)v[j], 0, XATTR_SIZE_MAX);
	}

	if(i < 2) /*if one of them is a literal value*/
	{
		if((l[!i] = getxattr(f, nd->dt[!i]->attr, v[!i], XATTR_SIZE_MAX)) > 0
		&& nd->dt[i]->type == v[!i][0])
			ret = read_value(v[!i], l[!i], nd->dt[!i]->val);
	}
	else
	{
		if((l[0] = getxattr(f, nd->dt[0]->attr, v[0], XATTR_SIZE_MAX)) > 0
		&& (l[1] = getxattr(f, nd->dt[1]->attr, v[1], XATTR_SIZE_MAX)) > 0
		&& v[0][0] == v[1][0])
		{
			ret = read_value(v[0], l[0], nd->dt[0]->val);
			read_value(v[1], l[1], nd->dt[1]->val);
		}
	}

	for(int j = 0; j < 2; j++)
		free(v[j]);

	return ret;
}

static int64_t dacmp(date_s *date1, date_s *date2, uint8_t flags)
{
	int64_t ycmp = date1->year - date2->year;
	int64_t mcmp = date1->month - date2->month;
	int64_t dcmp = date1->day - date2->day;

	if(flags & 1 && ycmp != 0)
		return ycmp;
	else if(flags & 2 && mcmp != 0)
		return mcmp;
	else if(flags & 4 && dcmp != 0)
		return dcmp;
	else
		return 0;
}

static int16_t ustrcmp(uint8_t *str1, uint8_t *str2)
{
	if(*str1 && *str2 && *str1 == *str2)
		return ustrcmp(str1+1, str2+1);
	else
		return (int16_t)(*str1 - *str2);
}
