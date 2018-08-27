/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:14:04 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/04 17:51:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

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

void	putboard(int rows[8])
{
	int	i;

	i = 0;
	while (i < 8)
		ft_putchar(rows[i++] + 49);
	ft_putchar('\n');
}

void	solve(int rows[8], int y)
{
	int	x;

	x = -1;
	while (++x < 8)
	{
		if (!attack(rows, x, y))
		{
			rows[y] = x;
			if (y == 7)
				putboard(rows);
			else
				solve(rows, y + 1);
		}
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int rows[8];

	solve(rows, 0);
}
