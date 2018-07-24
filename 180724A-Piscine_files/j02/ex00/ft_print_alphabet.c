#include "ft_print_alphabet.h"

void	ft_print_alphabet(void)
{
	char c;

	c = 97;

	while(c < 123)
    	printf("%c", c++);

	printf("\n");
}
