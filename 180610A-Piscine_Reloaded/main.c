#include <libf3.h>

int	main(int argc, char *argv[])
{
	ft_print_alphabet();
	ft_putchar('\n');
	ft_print_numbers();
	ft_putchar('\n');
	ft_putchar('\n');
	for (int i = -3; i < 3; i++)
	{
		if (i < 0)
		{
			ft_putchar('-');
			ft_putchar(48+(i*(-1)));
		}
		else
			ft_putchar((char)(48+i));
		ft_putchar(':');
		ft_putchar(' ');
		ft_is_negative(i);
		ft_putchar('\n');
	}
	return 0;
}
