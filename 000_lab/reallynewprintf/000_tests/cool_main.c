#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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
	ft_printf("MINE>\t[%*d]\n\n", 999);
   
	int	n = 123456789;
	char c = (char)n;
	short int s = (short int)n;
    ft_printf("MINE> (no cast)\t[%hhd]\n", 123456789);
	ft_printf("MINE> (cast)\t[%hhd]\n", c);
    printf(   "ORIG>\t\t[%hhd]\n", 123456789);
    ft_printf("MINE> (no cast)\t[%hd]\n", 123456789);
    ft_printf("MINE> (cast)\t[%hd]\n", s);
    printf(   "ORIG>\t\t[%hd]\n", 123456789);
	unsigned short int	us = (unsigned short int)18446744073709551615;
    ft_printf("MINE> (no cast)\t[%hu]\n", 18446744073709551615);
    ft_printf("MINE> (cast)\t[%hu]\n", us);
    printf(   "ORIG>\t\t[%hu]\n\n", 18446744073709551615);
	ft_printf("MINE>\t\t%jO, %jO\n", 0, USHRT_MAX);
	printf(	  "ORIG>\t\t%jO, %jO\n", 0, USHRT_MAX);
	return (0);
}
