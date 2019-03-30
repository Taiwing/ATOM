/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:25:37 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/12 13:42:17 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "tetros.h"
#include "libft.h"
#include "error.h"

static void	build_square(int b, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i * i < b)
		i++;
	d->l = i;
	if (!(d->square = (char **)malloc(d->l * sizeof(char *))))
		print_error();
	i = -1;
	while (++i < d->l)
	{
		if (!(d->square[i] = (char *)malloc(d->l)))
			print_error();
		j = -1;
		while (++j < d->l)
			d->square[i][j] = '.';
	}
}

static int	valid_pos(int x, int y, int t, t_data *d)
{
	int i;
	int	j;
	int	tetro[4][2];

	i = d->tetros[t];
	j = -1;
	while (++j < 4)
	{
		tetro[j][0] = x + g_tetros[i][j][0];
		tetro[j][1] = y + g_tetros[i][j][1];
		if (tetro[j][0] < 0 || tetro[j][0] > d->l - 1 || tetro[j][1] < 0 ||
			tetro[j][1] > d->l - 1 || d->square[tetro[j][0]][tetro[j][1]] != '.')
			return (0);
	}
	j = -1;
	while (++j < 4)
		d->square[tetro[j][0]][tetro[j][1]] = 'A' + t;
	return (1);
}

static void	remove_tetro(char c, char **square, int l)
{
	int	i;
	int	j;

	i = -1;
	while (++i < l)
	{
		j = -1;
		while (++j < l)
			square[i][j] = square[i][j] == c ? '.' : square[i][j];
	}
}

int			solve(int t, t_data *d)
{
	int	x;
	int y;

	if (t == d->tc)
		return (1);
	y = -1;
	while (++y < d->l)
	{
		x = -1;
		while (++x < d->l)
		{
			if (valid_pos(x, y, t, d))
			{
				if (solve(t + 1, d))
					return (1);
				remove_tetro('A' + t, d->square, d->l);
			}
		}
	}
	return (0);
}

int			get_square(int tc, int *tetros, char ***square)
{
	t_data	*d;
	int		i;
	int		l;

	if (!(d = (t_data *)malloc(sizeof(t_data))))
		print_error();
	d->tc = tc;
	d->tetros = tetros;
	build_square(d->tc * 4, d);
	while (!solve(0, d))
	{
		i = -1;
		while (++i < d->l)
			free(d->square[i]);
		free(d->square);
		build_square(d->l * d->l + 1, d);
	}
	*square = d->square;
	l = d->l;
	free(d);
	free(tetros);
	return (l);
}
