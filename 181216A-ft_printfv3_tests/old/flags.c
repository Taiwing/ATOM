#include <stdio.h>

int		main(void)
{
	int		i = 256;
	double	f = 2.99792458;
	printf("i = %##x\n", i);
	printf("f = %##00.0e\n", f);
	printf("i = %01$#056x\n", i);
	printf("test #015: %#015x\n", (unsigned int)0xff);
	printf("test #.15: %#.15x\n", (unsigned int)0xff);
	printf("test #015.15: %#015.15x\n", (unsigned int)0xff);
	return (0);
}
