#include <libf3.h>
#include <stdio.h>

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
	int nbr = 0, nbr_bis = 48, div, mod;
	ft_ft(&nbr);
	ft_putchar((char)nbr);
	ft_swap(&nbr, &nbr_bis);
	ft_putchar((char)nbr);
	ft_putchar('\n');
	ft_div_mod(nbr, nbr_bis, &div, &mod);
	printf("%d/%d = %d\nrest = %d\n", nbr, nbr_bis, div, mod);
	printf("iterative factorial:\n");
	printf("-5! = %d\n", ft_iterative_factorial(-5));
	printf("0! = %d\n", ft_iterative_factorial(0));
	printf("7! = %d\n", ft_iterative_factorial(7));
	printf("8! = %d\n", ft_iterative_factorial(8));
	printf("12! = %d\n", ft_iterative_factorial(12));
	printf("13! = %d\n", ft_iterative_factorial(13));
	printf("recursive factorial:\n");
	printf("-5! = %d\n", ft_recursive_factorial(-5));
    printf("0! = %d\n", ft_recursive_factorial(0));
    printf("7! = %d\n", ft_recursive_factorial(7));
    printf("8! = %d\n", ft_recursive_factorial(8));
    printf("12! = %d\n", ft_recursive_factorial(12));
    printf("13! = %d\n", ft_recursive_factorial(13));
	return 0;
}
