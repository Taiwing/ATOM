#include <libft/libft.h>

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		ft_putstr(ft_convert_base(argv[1], "0123456789", "01"));
		ft_putchar('\n');
	}
}
