#include "libft/libft.h"
#include "ft_atoi_base.h"

static int	is_nbr_valid(char *str, char *base, int *l);
static int	is_base_valid(char *base, int *b);
static int	conversion(char *str, int l, char *base, int b);
static int	powaaa(int a, int b);

int					ft_atoi_base(char *str, char *base)
{
	int b;
	int l;

	if (is_base_valid(base, &b) && is_nbr_valid(str, base, &l))
		return conversion(str, l, base, b);
	else
		return 0;
}

static int is_nbr_valid(char *str, char *base, int *l)
{
	char	*ptr;

	*l = 0;
	while(*l >= 0 && str[*l])
	{
		ptr = base;
		while (*ptr && !(str[*l] == *ptr
					|| (str[*l] == 43 && *l == 0) || (str[*l] == 45 && *l == 0)))
			ptr++;
		*l = *ptr ? *l + 1 : -1;
	}
	return (*l > 0);
}

static int	is_base_valid(char *base, int *b)
{
	char	*ptr;

	*b = 0;
	while (*b >= 0 && base[*b])
	{
		ptr = base;
		while (*ptr && (*ptr != base[*b] || ptr == &base[*b])
					&& *ptr != 43 && *ptr != 45)
			ptr++;
		*b = *ptr ? -1 : *b+1;
	}
	return (*b > 1);
}

static int conversion(char *str, int l, char *base, int b)
{
	int d;
	int	p;
	int	nbr;

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
