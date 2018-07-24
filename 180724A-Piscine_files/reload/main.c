#include <libf3.h>
#include <stdio.h>
#include <string.h>

void	f(int nb)
{
	printf("%d\n", nb);
}

int		is_clown(char *str)
{
	return (ft_strcmp(str, "clown") == 0);
}

int		main(int argc, char *argv[])
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
	printf("square roots:\n");
	printf("sqrt(49) = %d\n", ft_sqrt(49));
	printf("sqrt(52) = %d\n", ft_sqrt(52));
	printf("sqrt(692224) = %d\n", ft_sqrt(692224));
	printf("sqrt(-12) = %d\n", ft_sqrt(-12));
	printf("sqrt(123456) = %d\n", ft_sqrt(123456));
	printf("sqrt(10000) = %d\n", ft_sqrt(10000));
	char str[] = "Look at me, I'm a string!\n";
	char str2[] = "Look at me";
	char str3[] = "aaaaaaaaaaa";
	char str4[] = "zzzzzzzzzzzz";
	ft_putstr(str);
	printf("length = %d\n", ft_strlen(str));
	printf("cmp \"%s\" \"%s\": %d\n", str, str2, ft_strcmp(str, str2));
	printf("cmp \"%s\" \"%s\": %d\n", str, str3, ft_strcmp(str, str3));
	printf("cmp \"%s\" \"%s\": %d\n", str, str4, ft_strcmp(str, str4));
	printf("cmp \"%s\" \"%s\": %d\n", str, str, ft_strcmp(str, str));
	printf("%d\n%d\n%d\n%d\n", strcmp(str, str2), strcmp(str, str3),
	strcmp(str, str4), strcmp(str, str));
	ft_putstr(ft_strdup(str));
	int *arr = ft_range(12, 16);
	for(int i = 0; i < 4; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	free(arr);
	arr = ft_range(4683, 2);
	if (arr == NULL)
		printf("YEAHHHHH!!!!!! ARR IS NULL!\n");
	arr = ft_range(-16, -12);
	for(int i = 0; i < 4; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	free(arr);
	arr = ft_range(-3, 2);
	for(int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	ft_foreach(arr, 5, &f);
	printf("abs(-13) = %d\n", ABS(-13));
	printf("abs(12) = %d\n", ABS(12));
	char *list[] = {
		"lol", "dick", "clown", "lol", "clown", "clown", "pompidou", "clown", NULL
	};
	printf("clowns = %d\n", ft_count_if(list, &is_clown));
	return 0;
}
