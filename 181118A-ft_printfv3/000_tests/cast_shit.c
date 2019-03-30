#include <stdio.h>

int		main(void)
{
	int lol = 12;
	void *p = &lol;
	short unsigned int c = 49;
	printf("long int: %#lx\n", (unsigned long int)p);
	printf("void * : %p\n", p);
	printf("%c\n", c);
	return(0);
}
