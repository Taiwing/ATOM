#ifndef SOLVER_H
# define SOLVER_H

typedef struct	s_data
{
	int		tc;
	int		*tetros;
	int		l;
	char	**square;
}				t_data;

int	get_square(int tc, int *tetros, char ***square);

#endif
