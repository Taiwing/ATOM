#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;

	tab = min >= max ? NULL : (int *)malloc((max - min) * sizeof(int));
	while (tab && min < max--)
		tab[max - min] = max;
	return (tab);
}
