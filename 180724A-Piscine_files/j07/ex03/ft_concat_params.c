#include "ft_concat_params.h"
#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	int		size;
	char	**vptr;
	char	*ptr;
	char	*params;

	size = argc;
	vptr = argv;
	while (*vptr)
	{
		ptr = *vptr;
		while (*ptr++)
			size++;
		vptr++;
	}
	params = (char *)malloc(size);
	ptr = params;
	while (*argv)
	{
		while (**argv)
			*ptr++ = *(*argv)++;
		argv++;
		*ptr++ = *argv ? '\n' : '\0';
	}
	return params;
}
