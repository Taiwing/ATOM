#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int c = ft_printf("%03S\n", L"sa;of👾sapof");
	int o = printf("%03ls\n", L"sa;of👾sapof");
	printf("c = %d, o = %d\n", c, o);
	ft_printf("|%5ls|\n", L"👅");
	return (0);
}
