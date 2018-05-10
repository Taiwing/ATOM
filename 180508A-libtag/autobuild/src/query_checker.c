#include "include/tag_query.h"

char *ro_str[] = {
	"",
	"==",
	"!=",
	">=",
	"<=",
	">",
	"<",
};

static int check_par(char *query, size_t l, int *varray);
static int check_charplace(char *query, size_t l, int *varray);
static int check_rel_ops(char *query, size_t l, int *varray);

/*tests if the query is valid*/
int valid_query(char *query)
{
	size_t l = strlen(query);
	int (*check)(char *, size_t, int *);
	int err = 0, *verif_array = (int *)salloc(l * sizeof(int));

	for(int i = 0; i < 3 && err == 0; i++)
	{
		check = i == 0 ? &check_par :
						i == 1 ? &check_charplace :
						i == 2 ? &check_rel_ops :
						NULL;
		err = (*check)(query, l, verif_array);
	}

	if(err)
	{
		fprintf(stderr, "%s: incorrect query\n", PROGNAME);
		exit(EXIT_FAILURE);
	}

	free(verif_array);
	return 1;
}

static int check_par(char *query, size_t l, int *varray)
{
	int rpar = 0, lpar = 0, nest = 0;
	for(size_t i = 0; i < l; i++)
	{
		lpar += query[i] == LPAR ? 1 : 0;
		nest = lpar - rpar;
		switch(query[i])
		{
			case LPAR:
			case RPAR: varray[i] = nest;
					break;
			case AND:
			case OR:
			case XOR: varray[i] = -2;
					break;
			case NOT: varray[i] = -1;
					break;
			case ANT: varray[i] = 0;
				if(i < l-1)
					varray[++i] = 0;
				else
				 	return 1;
				break;
			default:  varray[i] = 0;
					break;
		}
		rpar += query[i] == RPAR ? 1 : 0;
		if(lpar - rpar < 0) return 1;
	}
	return (lpar != rpar);
}

static int check_charplace(char *query, size_t l, int *varray)
{
	for(size_t i = 0; i < l; i++) /*rules regarding character placement*/
	{
		switch(varray[i])
		{
			case -2:
				if(i == 0 || i == l-1
					|| (query[i-1] == '(' && varray[i-1] != 0)
					|| query[i+1] == ')'
					|| varray[i+1] == -2)
					return 1;
				break;
			case -1:
				if(i == l-1 || query[i+1] == ')' || varray[i+1] == -2)
					return 1;
				break;
			case 0:
				if((i != 0 && query[i-1] == ')' && varray[i-1] != 0)
					|| (i != l-1 && query[i+1] == '('))
					return 1;
				break;
		}
	}
	return 0;
}

static int check_rel_ops(char *query, size_t l, int *varray)
{
	for(int i = 1; i < 7; i++)
	{
		char *p = query, *r = NULL;
		do
		{
			r = strstr(p, ro_str[i]);
			p = r ? r+strlen(ro_str[i]) : p;
			if(r == query || p == &(query[l-1]))
				return 1;
			else if(r > query && *(r-1) != '\\') /*if it is unescaped*/
			{
				int rp = r-query; /*rel_op place*/
				if((varray[rp-1] < 0 || query[rp-1] == LPAR)
				  || (varray[p-query] < 0 || p[0] == RPAR))
					return 1;
				else
				{
					size_t llr[2] = {0, 0};
					char *left = r, *right = p;
					while(varray[left-query-1] == 0 && left > query)
						left--;
					llr[0] = r-left;
					while(varray[right-query+1] == 0 && right < query+l)
						right++;
					llr[1] = right-p;
					if(is_quoted(left, llr[0]) && is_quoted(p, llr[1]))
						return 1;
				}
			}
		}
		while(r);
	}
	return 0;
}
