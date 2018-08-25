#include "ft_print_words_tables.h"

void	ft_print_words_tables(char **tab)
{
	char	*str;

	while (*tab)
	{
		str = *tab++;
		while (*str)
			ft_putchar(*str++);
		ft_putchar('\n');
	}
}
