#include "ft_print_numbers.h"

void	ft_print_numbers(void)
{
	char num;

	num = 48;

 	while(num < 58)
		printf("%c", num++);

	printf("\n");
}
