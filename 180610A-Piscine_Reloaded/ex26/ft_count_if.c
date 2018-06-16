#include <libf3.h>

int	ft_count_if(char **tab, int(*f)(char*))
{
	int c;

	c = 0;
	while (*tab)
		c += (*f)(*tab++);
	return c;
}
