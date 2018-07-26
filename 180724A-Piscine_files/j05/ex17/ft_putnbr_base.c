#include "libft/libft.h"
#include "ft_putnbr_base.h"

static int	is_base_valid(char *base, int *b);
static void	print_nb(int nbr, char *base, int b);

void				ft_putnbr_base(int nbr, char *base)
{
	int b;

	if(is_base_valid(base, &b))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		print_nb(nbr, base, b);
		ft_putchar('\n');
	}
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

static void	print_nb(int nbr, char *base, int b)
{
	if (nbr/b != 0)
		print_nb(nbr/b, base, b);
	ft_putchar(base[nbr%b]);
}
