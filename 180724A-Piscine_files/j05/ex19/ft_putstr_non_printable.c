#include "libft/libft.h"
#include "ft_putstr_non_printable.h"

static void	putnbr_base(int nbr, char *base);
static void	print_nb(int nbr, char *base, int b);

void				ft_putstr_non_printable(char *str)
{
	if (*str == 0)
		return;
	else if (*str > 31 && *str < 127)
		ft_putchar(*str);
	else
	{
		ft_putchar(92);
		if (*str < 16)
			ft_putchar('0');
		putnbr_base((int)(*str), "0123456789abcdef");
	}
	ft_putstr_non_printable(str+1);
}

static void	putnbr_base(int nbr, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	print_nb(nbr, base, 16);
}

static void	print_nb(int nbr, char *base, int b)
{
	if (nbr/b != 0)
		print_nb(nbr/b, base, b);
	ft_putchar(base[nbr%b]);
}
