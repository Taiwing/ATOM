#include <libf3.h>

int	*ft_range(int min, int max)
{
	int	*arr;

	arr = min-max < 0 ? (int *)malloc(max - min) : NULL;
	while ((max--) - min > 0)
		arr[max - min] = max;
	return arr;
}
