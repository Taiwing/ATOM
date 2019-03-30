#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		br;
	char	hel[] = "Hello I am a string !";

	br = ft_printf("Hello World !\n");		/*yay*/
	br = ft_printf("br = %d\n", br);		/*fuck yay*/
	ft_printf("br2 = %d wuuuuut ??? it works !!!\n", br);
	ft_printf("simple %%s test: %s\n", "Coconut");
	ft_printf("MINE-> $1: %1$s\n", hel);
	printf("ORIG-> $1: %1$s\n", hel);
	ft_printf("MINE>\t[%*d]\n", 999);
	return (0);
}
