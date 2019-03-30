/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:26:49 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/14 16:35:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_square(int l, char **square)
{
	int	i;
	int	j;

	j = -1;
	while (++j < l)
	{
		i = -1;
		while (++i < l)
			ft_putchar(square[i][j]);
		ft_putchar(10);
	}
}

int		main(int argc, char **argv)
{
	int		l;
	int		i;
	int		tc;
	int		*tetros;
	char	**square;

	if (argc != 2)
	{
		ft_putstr("usage: fillit FILE\n");
		return (1);
	}
	tc = get_tetros(argv[1], &tetros);
	l = get_square(tc, tetros, &square);
	print_square(l, square);
	i = -1;
	while (++i < l)
		free(square[i]);
	free(square);
	return (0);
}
