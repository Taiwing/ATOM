#include <stdio.h>

void	ft_print_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_ft(int *nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
int		ft_iterative_factorial(int nb);
int		ft_recursive_factorial(int nb);
int		ft_sqrt(int nb);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	ft_print_alphabet();
	ft_print_numbers();
	ft_is_negative(-1);
	ft_is_negative(0);
	ft_is_negative(1);
	int n = 0;
	ft_ft(&n);
	printf("%d", n);
	int b = -12;
	ft_swap(&n, &b);
	printf( "n = %d, b = %d", n, b);
	int div, mod;
	ft_div_mod(b, n, &div, &mod);
	printf(" b / n = %d mod = %d", div, mod);
	printf(" %d", ft_iterative_factorial(-12));
	printf(" %d", ft_iterative_factorial(0));
	printf(" %d", ft_iterative_factorial(5));
	printf(" %d", ft_iterative_factorial(12));
	printf(" %d", ft_iterative_factorial(13));
        printf(" %d", ft_recursive_factorial(-12));
        printf(" %d", ft_recursive_factorial(0));
        printf(" %d", ft_recursive_factorial(5));
	printf(" %d", ft_recursive_factorial(12));
	printf(" %d\n", ft_recursive_factorial(13));
	int s = 0;
	for (int i = -12; i < 962; i++)
	{
		s = ft_sqrt(i);
		if (s)
			printf("sqrt(%d) = %d\n", i, s);
	}
	char *h = "Hello, I am a string !";
	char *y = "yoann";
	char *y2 = "yoan";
	char *y3 = "yohan";
	ft_putstr(h);
	printf(" %d\n", ft_strlen(h));
	ft_putstr(y);
    printf(" %d\n", ft_strlen(y));
	printf("ft_strcmp(%s, %s) = %d\n", y, h, ft_strcmp(y, h));
	printf("ft_strcmp(%s, %s) = %d\n", y, y, ft_strcmp(y, y));
	printf("ft_strcmp(%s, %s) = %d\n", y, y2, ft_strcmp(y, y2));
	printf("ft_strcmp(%s, %s) = %d\n", y, y3, ft_strcmp(y, y3));
	printf("ft_strcmp(%s, %s) = %d\n", y2, y3, ft_strcmp(y2, y3));
	return (0);
}
