#include "ft_range.h"
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *tab;

	i = 0;
	tab = (max - min) > 0 ? malloc((max - min) * sizeof(int)) : NULL;
	while(min < max)
		tab[i++] = min++;

	return tab;
}
