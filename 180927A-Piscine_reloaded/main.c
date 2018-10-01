#include <stdio.h>
#include <stdlib.h>
#include "ex22/ft_abs.h"

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
char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
void	ft_foreach(int *tab, int length, void(*f)(int));
int		ft_count_if(char **tab, int(*f)(char*));

void	putint(int nb)
{
	printf("%d\n", nb);
}

int		isyoyo(char *str)
{
	return (!ft_strcmp(str, "yoann"));
}

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
	printf("ft_strdup(y) = %s\n", ft_strdup(y));
	printf("ft_strdup(\"\\0\") = %s\n", ft_strdup("\0"));
	printf("ft_strdup(NULL) = %s\n", ft_strdup(NULL));
	int *tab;
	for (int min = -5, max = 6; min != 2; min++, max--)
	{
		tab = ft_range(min, max);
		printf("min = %d\nmax = %d\n", min, max);
		ft_foreach(tab, max - min, &putint);
		if (!tab)
			printf("NULL\n");
		else
			free(tab);
		printf("\n");
	}
	printf("%d\n", ABS(-12));
	printf("%d\n", ABS(0));
	printf("%d\n", ABS(15));
	char *names[] = {"yoann", "john", "robert", "yoann", "jean-claude", "yoann", NULL};
	printf("%d\n", ft_count_if(names, &isyoyo));
	return (0);
}
