#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		i;
	int		size;
	int		*tab;

	size = start <= end ? end - start + 1 : start - end + 1;
	if (!(tab = (int *)malloc(size * sizeof(int))))
		return (0);
	i = 0;
	if (start <= end)
	{
		while (start <= end)
			tab[i++] = start++;
	}
	else
	{
		while (start >= end)
			tab[i++] = start--;
	}
	return (tab);
}
