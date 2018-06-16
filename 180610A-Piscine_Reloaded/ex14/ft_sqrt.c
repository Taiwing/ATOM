#include <libf3.h>

/*for non-retards*/
/*int	ft_sqrt(int nb)
{
	int	bit;
	int root;

	bit = nb & 0xF;
	if (nb <= 0 || (bit != 0 && bit != 1 && bit != 4 && bit != 9))
		return 0;

	root = 0;
	bit = 1 << ((sizeof(int)*8)-2);
	while (bit > nb)
		bit >>= 2;
	while (bit != 0)
	{
		if (nb >= root + bit)
		{
			nb -= root + bit;
			root = (root >> 1) + bit;
		}
		else
			root >>= 1;
		bit >>= 2;
	}
	return (nb == 0 ? root : 0);
}*/

static int	non_square_test(int nb);
static int	first_root(int *cur, int *nbp, int *hun);

/*for me*/
/*TODO: make it 42-compatible*/
/*first study the function to rememeber how it works*/
/*and then erase comments and empty lines*/
int					ft_sqrt(int nb)
{
	int nbp;
	int hun;
	int cur;
	int root;
	int x;
	int y;

	if (non_square_test(nb))
		return 0;

	nbp = nb;
	root = first_root(&cur, &nbp, &hun);

	/*while nb is more than two digits long*/
	while (hun > 1)
	{
		nb -= nbp * hun;
		nbp = nb / (hun /= 100);

		cur = cur * 100 + nbp;
		x = cur / (20 * root);
		y = x * ((20 * root) + x);

		root = (10 * root) + x;
		cur = cur - y;
	}

	return (cur ? 0 : root);
}

static int	non_square_test(int nb)
{
	int	lb;

	lb = nb & 0xF;
	return (nb <= 0 || (lb != 0 && lb != 1 && lb != 4 && lb != 9));
}

static int	first_root(int *cur, int *nbp, int *hun)
{
	int x;

	*hun = 1;
	while (*nbp >= 100)
	{
		*nbp /= 100;
		*hun *= 100;
	}
	x = 9;
	while (x * x > *nbp)
		x--;
	*cur = *nbp - (x * x);
	return x;
}
