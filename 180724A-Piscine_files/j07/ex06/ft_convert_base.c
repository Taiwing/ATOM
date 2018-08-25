#include "libft/libft.h"
#include "ft_convert_base.h"
#include <stdlib.h>

static int	atoi_base(char *str, char *base);
static int	powaaa(int a, int b);


char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ret;
	int		b;
	int		p;
	int		nb;

	nb = atoi_base(nbr, base_from);
	b = -1;
	while (base_to[++b]);
	p = 0;
	nbr = (char *)malloc(65 * sizeof(char));
	while (nb)
	{
		nbr[p++] = nb < 0 ? '-' : base_to[nb % b];
		nb = nb < 0 ? nb * -1 : nb / b;
	}
	nbr[p] = '\0';
	ret = (char *)malloc(p * sizeof(char));
	b = *nbr == '-' ? 1 : 0;
	while (nbr[b])
		ret[--p] = nbr[b++];
	*ret = *nbr == '-' ? '-' : *ret;
	free(nbr);
	return ret;
}

static int atoi_base(char *str, char *base)
{
	int l;
	int b;
	int	p;
	int d;
	int	nbr;

	b = -1;
	while (base[++b]);
	l = -1;
	while (str[++l]);
	p = l;
	nbr = 0;
	while (p--)
	{
		d = 0;
		while (str[p] != base[d] && str[p] != 43 && str[p] != 45)
			d++;
		if (str[p] == 43 || str[p] == 45)
			nbr *= str[p] == 45 ? -1 : 1;
		else
			nbr += d * powaaa(b, l-p-1);
	}
	return nbr;
}


static int powaaa(int a, int b)
{
	return (b ? a * powaaa(a, b-1) : 1);
}
