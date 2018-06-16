#include "libf4.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	while (mem && size > 0)
		((char *)mem)[--size] = 0;
	return mem;
}
