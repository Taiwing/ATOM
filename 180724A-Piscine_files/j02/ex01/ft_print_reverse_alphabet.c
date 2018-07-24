#include "ft_print_reverse_alphabet.h"

void	ft_print_reverse_alphabet(void)
{
	char c;

	c = 122;

	while(c > 96)
 		printf("%c", c--);

	printf("\n");
}
