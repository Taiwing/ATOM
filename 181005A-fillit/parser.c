/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:27:22 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/12 13:38:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "tetros.h"
#include "error.h"

static int	check_tetro(int tetro[4][2])
{
	int	i;
	int j;
	int	x_ref;
	int	y_ref;

	x_ref = tetro[0][0];
	y_ref = tetro[0][1];
	i = -1;
	j = 1;
	while (j != 4 && ++i < 19)
	{
		j = 1;
		while (j < 4 && tetro[j][0] - x_ref == g_tetros[i][j][0]
				&& tetro[j][1] - y_ref == g_tetros[i][j][1])
			j++;
	}
	if (i == 19)
		print_error();
	return (i);
}

static void	read_line(int fd, int *bc, int tetro[4][2], int y)
{
	int		x;
	int		r;
	char	buf[5];

	if ((r = read(fd, buf, 5)) != 5)
		print_error();
	x = -1;
	while (++x < r)
	{
		if (x < 4 && buf[x] == '#')
		{
			if (++(*bc) > 3)
				print_error();
			tetro[*bc][0] = x;
			tetro[*bc][1] = y;
		}
		else if ((x < 4 && buf[x] != '.') || (x == 4 && buf[x] != 10))
			print_error();
	}
	if (y == 3 && *bc < 3)
		print_error();
}

static int	*read_file(int fd, int it, int *tc)
{
	int		i;
	int		tid;
	char	end;
	int 	*tetros;
	int		tetro[4][2];

	i = -1;
	tid = -1;
	while (++i < 4)
		read_line(fd, &tid, tetro, i);
	tid = check_tetro(tetro);
	end = 0;
	if ((i = read(fd, &end, 1)) < 0 || (i && end != 10))
		print_error();
	(*tc)++;
	if (!(tetros = i ? read_file(fd, it + 1, tc)
		: (int *)malloc(*tc * sizeof(int))))
		print_error();
	tetros[it] = tid;
	return (tetros);
}

int 		get_tetros(char *file, int **tetros)
{
	int	fd;
	int tc;

	tc = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error();
	else
		*tetros = read_file(fd, 0, &tc);
	return (tc);
}
