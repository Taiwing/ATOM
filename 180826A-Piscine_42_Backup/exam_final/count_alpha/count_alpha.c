#include <stdio.h>
#define	MIN(C) (C > 64 && C < 91 ? C + 32 : C)

enum	e_ind {LET = 0, OCC, IND};

int		g_tab[26][3] = 
{
	{'a', 0, 0},
	{'b', 0, 0},
	{'c', 0, 0},
	{'d', 0, 0},
	{'e', 0, 0},
	{'f', 0, 0},
	{'g', 0, 0},
	{'h', 0, 0},
	{'i', 0, 0},
	{'j', 0, 0},
	{'k', 0, 0},
	{'l', 0, 0},
	{'m', 0, 0},
	{'n', 0, 0},
	{'o', 0, 0},
	{'p', 0, 0},
	{'q', 0, 0},
	{'r', 0, 0},
	{'s', 0, 0},
	{'t', 0, 0},
	{'u', 0, 0},
	{'v', 0, 0},
	{'w', 0, 0},
	{'x', 0, 0},
	{'y', 0, 0},
	{'z', 0, 0}
};

void	fill_tab(char *str)
{
	int		c;

	c = 0;
	while (*str)
	{
		if (MIN(*str) > 96 && MIN(*str) < 123)
		{
			g_tab[MIN(*str) - 97][OCC]++;
			g_tab[MIN(*str) - 97][IND] = g_tab[MIN(*str) - 97][IND] == 0 ? ++c : g_tab[MIN(*str) - 97][IND];
		}
		str++;
	}
}

int		get_indmax(void)
{
	int		i;
	int		max;

	max = 0;
	i = 0;
	while (i < 26)
	{
		max = g_tab[i][IND] > max ? g_tab[i][IND] : max;
		i++;
	}
	return (max);
}

void	show_tab(void)
{
	int		indmax;
	int		cur;
	int		i;

	indmax = get_indmax();
	cur = indmax ? 1 : 0;
	while (cur <= indmax && indmax)
	{
		i = 0;
		while (g_tab[i][IND] != cur)
			i++;
		if (cur == 1)
			printf("%d%c", g_tab[i][OCC], g_tab[i][LET]);
		else
			printf(", %d%c", g_tab[i][OCC], g_tab[i][LET]);
		cur++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		fill_tab(argv[1]);
		show_tab();
	}
	printf("\n");
	return (0);
}
