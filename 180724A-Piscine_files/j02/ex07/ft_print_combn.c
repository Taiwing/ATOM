#include "ft_print_combn.h"

static void	load_ammo(int ammo[10], int bank[255][10], int n);
static int	loaded(int ammo[10]);
static void	get_next_comb(int ammo[10], int bank[255][10], int c, int n);
static int	check_comb(int ammo[10], int bank[255][10], int c, int n);

void								ft_print_combn(int n)
{
	int c;
	int dn;
	int	ammo[10];
	int	bank[255][10];

	c = 0;
	load_ammo(ammo, bank, n);
	while (1)
	{
		dn = 0;
		while (dn < n)
			ft_putchar(bank[c][dn++] + 48);
		c++;
		if (loaded(ammo))
		{
			ft_putchar(',');
			ft_putchar(' ');
			get_next_comb(ammo, bank, c, n);
		}
		else
			break;
	}
}

static void	load_ammo(int ammo[10], int bank[255][10], int n)
{
	int	d;
	int load;

	if (n == 2 || n == 9)
		load = 9;
	else if (n == 3 || n == 8)
		load = 36;
	else if (n == 4 || n == 7)
		load = 84;
	else if (n == 5 || n == 6)
		load = 126;
	else
		load = 1;

	d = 10;
	while (d)
		ammo[--d] = load;
	while (n--)
	{
		ammo[n]--;
		bank[0][n] = n;
	}
}

static int		loaded(int ammo[10])
{
	int d;

	d = 10;
	while (ammo[--d] == 0)
	{
		if (d == 0)
			return 0;
	}
	return 1;
}

static void	get_next_comb(int ammo[10], int bank[255][10], int c, int n)
{
	int d;

	d = n;
	while (d-- > 0)
		bank[c][d] = bank[c-1][d];

	while (1)
	{
		d = n-1;
		while (d >= 0 && bank[c][d] == 9)
			bank[c][d--] = 0;
		bank[c][d]++;

		if (check_comb(ammo, bank, c, n))
		{
			while (n--)
				ammo[bank[c][n]]--;
			break;
		}
	}
}

static int	check_comb(int ammo[10], int bank[255][10], int c, int n)
{
	int ret;
	int i[4]; /*i0 and i1 are dn, i2 is dc, i3 is eq*/

	ret = 1;
	i[0] = n;
	while ((i[1] = --i[0]) && ret)
	{
		ret = (ammo[bank[c][i[0]]] != 0); /*ammo test*/
		while (i[1]-- && ret)	/*digit redundancy test*/
			ret = (bank[c][i[0]] != bank[c][i[1]]);
	}
	i[2] = c;
	while (i[2]-- && ret)	/*bank test*/
	{
		i[3] = 0;
		i[0] = n;
		while (i[0]-- && ret)
		{
			i[1] = n;
			while (i[1]--)
				i[3] += (bank[c][i[0]] == bank[i[2]][i[1]]);
			ret = (i[3] != n);
		}
	}
	return ret;
}

/*static int	check_comb(int ammo[10], int bank[255][10], int c, int n)
{
	int i[4]; i0 and i1 are dn, i2 is dc, i3 is eq

	i[0] = n;
	while ((i[1] = --i[0]))
	{
		while (i[1]--)	digit redundancy test and ammo test
		{
			if (bank[c][i[0]] == bank[c][i[1]] || ammo[bank[c][i[0]]] == 0)
				return 0;
		}
	}
	i[2] = c;
	while (i[2]--)	bank test
	{
		i[3] = 0;
		i[0] = n;
		while (i[0]--)
		{
			i[1] = n;
			while (i[1]--)
				i[3] += (bank[c][i[0]] == bank[i[2]][i[1]]);
			if (i[3] == n)
				return 0;
		}
	}
	return 1;
}*/

/*static int	check_comb(int ammo[10], int bank[255][10], int c, int n)
{
	int eq;
	int	dc;
	int	dn[2];

	dc = c;
	dn[0] = n;
	while (dn[0]--)
	{
		dn[1] = dn[0];
		if (ammo[bank[c][dn[0]]] == 0) ammo test
			return 0;
		while (dn[1]--)	digit redundancy test
		{
			if (bank[c][dn[0]] == bank[c][dn[1]])
				return 0;
		}
	}
	while (dc--)	bank test
	{
		eq = 0;
		dn[0] = n;
		while (dn[0]--)
		{
			dn[1] = n;
			while (dn[1]--)
				eq += (bank[c][dn[0]] == bank[dc][dn[1]]);
			if (eq == n)
				return 0;
		}
	}

	return 1;
}*/
