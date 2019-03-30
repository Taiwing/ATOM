#include <stdio.h>
#include <stdlib.h>

typedef struct	s_test
{
	int		nb;
	char	*ptr;
}				t_test;

int		main(void)
{
	t_test *lol = (t_test *)malloc(sizeof(t_test));
	printf("nb = %d\nptr = %p\n", lol->nb, lol->ptr);
	return (0);
}
