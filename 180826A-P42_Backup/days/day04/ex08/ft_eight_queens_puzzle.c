/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:13:33 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/04 17:45:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		attack(int rows[8], int x, int y)
{
	int i;

	i = 0;
	if (y == 0)
		return (0);
	while (i < y)
	{
		if (rows[i] == x || rows[i] == x + y - i || rows[i] == x - y + i)
			return (1);
		i++;
	}
	return (0);
}

void	solve(int rows[8], int y, int *c)
{
	int	x;

	x = -1;
	while (++x < 8)
	{
		if (!attack(rows, x, y))
		{
			rows[y] = x;
			if (y == 7)
				(*c)++;
			else
				solve(rows, y + 1, c);
		}
	}
}

int		ft_eight_queens_puzzle(void)
{
	int c;
	int rows[8];

	c = 0;
	solve(rows, 0, &c);
	return (c);
}
