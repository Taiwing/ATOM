#include "include/ft_printf.h"

int		main(void)
{
	int		br;

	br = ft_printf("Hello World !\n");		/*yay*/
	br = ft_printf("br = %d\n", br);		/*fuck yay*/
	ft_printf("br2 = %d wuuuuut ??? it works !!!\n", br);
	return (0);
}
