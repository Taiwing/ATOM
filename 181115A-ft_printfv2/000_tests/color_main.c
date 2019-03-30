#include "libft.h"
#include <stdio.h>

int		main(void)
{
	int w, n;
	ft_putstr("putstr test\n");
	ft_putstr("\x1b[31mred test lol\n\x1b[0mnormal test\n\n");
	
	printf("printf test\n");
	w = printf("\x1b[31mstringtest: \x1b[0m");
	printf("%d\n", w);
	n = printf("stringtest: ");
	printf("%d\n", n);
	return (0);
}
