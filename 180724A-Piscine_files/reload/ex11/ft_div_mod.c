#include <libf3.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*mod = (b != 0 ? a - ((*div = a/b) * b) : *mod);
}
