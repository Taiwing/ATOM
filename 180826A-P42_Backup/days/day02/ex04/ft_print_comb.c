/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 05:00:41 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/02 17:00:40 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

static void	load_ammo(int ammo[10], int bank[255][10])
{
	int	d;
	int n;

	d = 10;
	n = 3;
	while (d)
		ammo[--d] = 36;
	while (n--)
	{
		ammo[n]--;
		bank[0][n] = n;
	}
}

static int	loaded(int ammo[10])
{
	int d;

	d = 10;
	while (ammo[--d] == 0)
	{
		if (d == 0)
			return (0);
	}
	return (1);
}

static int	check_comb(int ammo[10], int bank[255][10], int c)
{
	int ret;
	int i[4];

	ret = 1;
	i[0] = 3;
	while ((i[1] = --i[0]) && ret)
	{
		ret = (ammo[bank[c][i[0]]] != 0);
		while (i[1]-- && ret)
			ret = (bank[c][i[0]] != bank[c][i[1]]);
	}
	i[2] = c;
	while (i[2]-- && ret)
	{
		i[3] = 0;
		i[0] = 3;
		while (i[0]-- && ret)
		{
			i[1] = 3;
			while (i[1]--)
				i[3] += (bank[c][i[0]] == bank[i[2]][i[1]]);
			ret = (i[3] != 3);
		}
	}
	return (ret);
}

static void	get_next_comb(int ammo[10], int bank[255][10], int c)
{
	int n;
	int d;

	n = 3;
	d = n;
	while (d-- > 0)
		bank[c][d] = bank[c - 1][d];
	while (1)
	{
		d = n - 1;
		while (d >= 0 && bank[c][d] == 9)
			bank[c][d--] = 0;
		bank[c][d]++;
		if (check_comb(ammo, bank, c))
		{
			while (n--)
				ammo[bank[c][n]]--;
			break ;
		}
	}
}

void		ft_print_comb(void)
{
	int c;
	int dn;
	int	ammo[10];
	int	bank[255][10];

	c = 0;
	load_ammo(ammo, bank);
	while (1)
	{
		dn = 0;
		while (dn < 3)
			ft_putchar(bank[c][dn++] + 48);
		c++;
		if (loaded(ammo))
		{
			ft_putchar(',');
			ft_putchar(' ');
			get_next_comb(ammo, bank, c);
		}
		else
			break ;
	}
}
