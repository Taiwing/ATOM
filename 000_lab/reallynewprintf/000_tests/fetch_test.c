#include <stdio.h>
#include <stdlib.h>

typedef struct	s_ex
{
	int			i;
	double		f;
}				t_ex;

void			fetch(char c, void *ptr)
{
	if (c == 'i')
		*(int *)ptr = 42;
	else if (c == 'f')
		*(double *)ptr = 2.99792458;
}

int				main(void)
{
	t_ex	*n;

	n = (t_ex *)malloc(sizeof(t_ex));
	fetch('i', (void *)(&(n->i)));
	fetch('f', (void *)(&(n->f)));
	printf("i = %d\nf = %e\n", n->i, n->f);
	free(n);
	return (0);
}
