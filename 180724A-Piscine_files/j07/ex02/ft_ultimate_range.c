#include "ft_ultimate_range.h"
#include "libft/libft.h"
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	*range = (max - min) > 0 ? malloc((max - min) * sizeof(int)) : NULL;
	while(min < max)
		(*range)[i++] = min++;

	return i;
}
