#ifndef OPS_FUNC_H
# define OPS_FUNC_H
# include "ops.h"

typedef struct s_opfunc
{
	char c;
	int (*f)(int, int);
} t_opfunc;

t_opfunc g_opptab[] =
{
	{'+', &ft_add},
	{'-', &ft_sub},
	{'*', &ft_mul},
	{'/', &ft_div},
	{'%', &ft_mod},
	{'.', 0}
};

#endif
